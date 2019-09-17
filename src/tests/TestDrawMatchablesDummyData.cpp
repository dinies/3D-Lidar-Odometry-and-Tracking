#include "../loam/Visualizer.hpp"

using namespace srrg2_core;
using namespace srrg2_qgl_viewport;
using namespace Loam;


int main( int argc, char** argv){

  const sphericalImage_params params(
    64, //num_vertical_rings
    768, //num_points_ring
    7, //epsilon_times
    0.15, //epsilon_radius
    2.1, //depth_differential_threshold
    7,  //min_neighboors_for_normal
    8, //epsilon_c
    1.5, //epsilon_d
    0.3, //epsilon_n
    1, //epsilon_l
    1, //epsilon_dl
    1, //epsilon_p
    1 //epsilon_dp
  );
    
  SphericalDepthImage sph_Image;
  PointNormalColor3fVectorCloud cloud;


  PointNormalColor3f min_elev;
  min_elev.coordinates() = Vector3f( 2,7,10);
  cloud.push_back( min_elev);
  PointNormalColor3f max_elev;
  max_elev.coordinates() = Vector3f( 2,7,-10);
  cloud.push_back( max_elev);

  PointNormalColor3fVectorCloud p1 = Visualizer::createPlane(
    Vector3f( -35.,-35.,0.),Vector3f( 0.,0.,1.),
    Vector3f( -1.,1.,0.).normalized(), 18, 14, 0.25, 0.25);

  PointNormalColor3fVectorCloud p2 = Visualizer::createPlane(
    Vector3f( 0.,35.,0.),Vector3f( 0.,0.,1.),
    Vector3f( 1.,0.,0.), 18, 14, 0.25, 0.25);

  PointNormalColor3fVectorCloud p3 = Visualizer::createPlane(
    Vector3f( 35.,0.,0.),Vector3f( 0.,0.,1.),
    Vector3f( 0.,1.,0.).normalized(), 18, 14, 0.25, 0.25);

  PointNormalColor3fVectorCloud p4 = Visualizer::createPlane(
    Vector3f( -35.,35.,0.),Vector3f( 0.,0.,1.),
    Vector3f( 1.,1.,0.), 18, 14, 0.25, 0.25);

  PointNormalColor3fVectorCloud p5 = Visualizer::createPlane(
    Vector3f( 35.,-35.,0.),Vector3f( 0.,0.,1.),
    Vector3f( 1.,1.,0.), 18, 14, 0.25, 0.25);


  PointNormalColor3fVectorCloud p6 = Visualizer::createPlane(
    Vector3f( 0.,-35.,0.),Vector3f( 0.,0.,1.),
    Vector3f( 1.,0.,0.), 18, 14, 0.25, 0.25);


  PointNormalColor3fVectorCloud p7 = Visualizer::createPlane(
    Vector3f( -35.,0.,0.),Vector3f( 0.,0.,1.),
    Vector3f( 0.,1.,0.), 18, 14, 0.25, 0.25);

  PointNormalColor3fVectorCloud p8 = Visualizer::createPlane(
    Vector3f( 35.,35.,0.),Vector3f( 0.,0.,1.),
    Vector3f( -1.,1.,0.), 18, 14, 0.25, 0.25);


  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p1.begin()),
    std::make_move_iterator( p1.end())
  );

  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p2.begin()),
    std::make_move_iterator( p2.end())
  );

  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p3.begin()),
    std::make_move_iterator( p3.end())
  );
  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p4.begin()),
    std::make_move_iterator( p4.end())
  );

  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p5.begin()),
    std::make_move_iterator( p5.end())
  );

  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p6.begin()),
    std::make_move_iterator( p6.end())
  );

  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p7.begin()),
    std::make_move_iterator( p7.end())
  );

  cloud.insert(
    cloud.end(),
    std::make_move_iterator( p8.begin()),
    std::make_move_iterator( p8.end())
  );


   
  
  const float points_size = 2.0;

  sph_Image = SphericalDepthImage(cloud,params);
  sph_Image.initializeIndexImage();
  sph_Image.executeOperations();
  std::vector<Matchable> matchables = sph_Image.clusterizeCloud();
   
  PointNormalColor3fVectorCloud features_cloud;
  features_cloud.reserve( cloud.size());

  for ( auto & m: matchables ){
    
    //todo add a method in matchable class that returns the vector of points;
  }


  QApplication qapp(argc, argv);
  ViewerCoreSharedQGL viewer(argc, argv, &qapp);
  ViewerCanvasPtr canvas1 = viewer.getCanvas("drawingPlaneBeforeCleaning");
  std::thread processing_thread1( Visualizer::visualizeCloud, canvas1, cloud, points_size);

  ViewerCanvasPtr canvas2 = viewer.getCanvas("drawingPlaneAfterFlatSurfRemoval");
  std::thread processing_thread2( Visualizer::visualizeCloud, canvas2,features_cloud, points_size);

  
  viewer.startViewerServer();

  processing_thread1.join();
  processing_thread2.join();
  


  return 0;
}
