#include "Clusterer.hpp"

namespace Loam{

  Clusterer::Clusterer( 
         const  PointNormalColor3fVectorCloud & t_cloud,
         vector<vector<list<DataPoint>>> t_index_image,
         const sphericalImage_params t_params):
    m_cloud(t_cloud),
    m_params(t_params){

    m_image.resize(m_params.num_vertical_rings);
    for ( auto & vec: m_image){
      vec.resize( m_params.num_points_ring);
    }

    m_pathMatrix.resize(m_params.num_vertical_rings);
    for ( auto & vec: m_pathMatrix){
      vec.resize( m_params.num_points_ring);
    }

    flattenIndexImage_populatePathMatrix(
      t_cloud, t_index_image);

  }
         

  vector<cluster> Clusterer::findClusters(){
    vector<cluster> clusters;
    //find a good number to preserve space

    bool allCellsChosen = false;
    while( not  allCellsChosen ){
      matCoords coords =  findSeed();
      if( coords.row == -1 or coords.col == -1){
        allCellsChosen = true;
      }
      else{
        cluster c = computeCluster( coords);
        clusters.push_back( c);
      }
    }
    return clusters;
  }

  matCoords Clusterer::findSeed(){

    matCoords mC;
    bool found = false;
    for (unsigned int row =0; row < m_pathMatrix.size() ; ++row){
      for (unsigned int col=0; col < m_pathMatrix[0].size(); ++col){
        if (! m_pathMatrix[row][col].hasBeenChoosen){
          found = true;
          mC.row = row;
          mC.col = col;
          break;
          break;
        }
      }
    }
    if (! found){
      mC.row = -1;
      mC.col = -1;
    }
    return mC;
  }

  vector<pathCell> Clusterer::findNeighboors(pathCell & t_pathCell){
    matCoords upLeft( t_pathCell.matCoords.row -1, t_pathCell.matCoords.col -1);
    matCoords up( t_pathCell.matCoords.row -1, t_pathCell.matCoords.col);
    matCoords upRight( t_pathCell.matCoords.row -1, t_pathCell.matCoords.col +1);
    matCoords left( t_pathCell.matCoords.row , t_pathCell.matCoords.col -1);
    matCoords right( t_pathCell.matCoords.row , t_pathCell.matCoords.col +1);
    matCoords downLeft( t_pathCell.matCoords.row +1, t_pathCell.matCoords.col -1);
    matCoords down( t_pathCell.matCoords.row +1, t_pathCell.matCoords.col );
    matCoords downRight( t_pathCell.matCoords.row +1, t_pathCell.matCoords.col +1);

    vector<matCoords> coords = {
      upLeft, up, upRight, left, right, downLeft, down, downRight
    };

    vector<pathCell> cells;
    cells.reserve( coords.size());

    for( auto& coord: coords){
      if ( coord.row >= 0 and coord.row < m_params.num_vertical_rings and
          coord.col >= 0 and coord.col < m_params.num_points_ring and
          not m_pathMatrix[coord.row][coord.col].hasBeenChoosen){
        cells.push_back( m_pathMatrix[coord.row][coord.col]);
      }
    }
    return cells;
  }

  cluster Clusterer::computeCluster(const matCoords & t_seed_coords){
    stack<pathCell> cellStack;
    cellStack.push( m_pathMatrix[t_seed_coords.row][t_seed_coords.col]);
    cluster c;
    int numPointsCluster =0;
    Eigen::Vector3f cumulative_mu;
    Eigen::Matrix3f cumulative_S;
    vector<int> indexes;
    //find a good number to preserve space
    
    while( not cellStack.empty()){
      pathCell currCell = cellStack.top();
      vector<pathCell> neighboors=  findNeighboors( currCell);
      ++numPointsCluster;
      cellStack.pop();
      DataPoint currDataPoint = m_image[currCell.matCoords.row][currCell.matCoords.col];
      const Eigen::Vector3f currCart_coords= m_cloud[ currDataPoint.getIndexContainer()].coordinates();
      const Eigen::Vector3f currNormal= m_cloud[ currDataPoint.getIndexContainer()].normal();

      for ( auto & otherCell: neighboors){
        if( abs( currCell.depth - otherCell.depth) < m_params.depth_differential_threshold){
          DataPoint otherDataPoint = m_image[otherCell.matCoords.row][otherCell.matCoords.col];
          const Eigen::Vector3f otherCart_coords=
            m_cloud[ otherDataPoint.getIndexContainer()].coordinates();
          const Eigen::Vector3f otherNormal= m_cloud[ otherDataPoint.getIndexContainer()].normal();
          const float diff_cartesian = ( currCart_coords - otherCart_coords).norm();
          const float diff_normal= 1- ( currNormal.transpose() * otherNormal);
          if ( diff_cartesian < m_params.epsilon_d and diff_normal < m_params.epsilon_n){
            cellStack.push( otherCell);
          }
        }
      }

      cumulative_mu += currCart_coords;
      cumulative_S += currCart_coords * currCart_coords.transpose();
      indexes.push_back(currDataPoint.getIndexContainer());
    }
    Eigen::Matrix3f S = cumulative_S/numPointsCluster;
    c.mu = cumulative_mu/ numPointsCluster;
    c.sigma = S - c.mu*c.mu.transpose();

    return c;
  }




  void  Clusterer::flattenIndexImage_populatePathMatrix(
      const  PointNormalColor3fVectorCloud & t_cloud,
      vector<vector<list<DataPoint>>> t_index_image){

   
    for (unsigned int row =0; row < t_index_image.size() ; ++row){
      for (unsigned int col=0; col < t_index_image[0].size(); ++col){
        DataPoint nearestPoint = DataPoint();
        if ( t_index_image[row][col].size() > 0 ){
          for ( auto& elem: t_index_image[row][col]){
            if ( nearestPoint.getIndexContainer() !=  -1){
              const Eigen::Vector3f nearest_cartesian_coords =
                m_cloud[nearestPoint.getIndexContainer()].coordinates();
              const Eigen::Vector3f nearest_spherical_coords =
                SphericalDepthImage::directMappingFunc( nearest_cartesian_coords);
              const Eigen::Vector3f current_cartesian_coords =
                m_cloud[elem.getIndexContainer()].coordinates();
              const Eigen::Vector3f current_spherical_coords =
                SphericalDepthImage::directMappingFunc( current_cartesian_coords);
              if ( nearest_spherical_coords.z() > current_spherical_coords.z() ){
                nearestPoint = elem;
              }
            }
            else{
              nearestPoint = elem;
            }
          }
        }
        m_image[row][col] = nearestPoint;
        if( nearestPoint.getIndexContainer() == -1){
          const Eigen::Vector3f cart_coords =
            m_cloud[nearestPoint.getIndexContainer()].coordinates();
          const Eigen::Vector3f sph_coords =
            SphericalDepthImage::directMappingFunc( cart_coords);
          m_pathMatrix[row][col].depth = sph_coords.z();
        }
        m_pathMatrix[row][col].matCoords = matCoords( row,col);
      }
    }
  }
}


