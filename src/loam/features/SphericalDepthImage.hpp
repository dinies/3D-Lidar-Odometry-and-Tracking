#pragma once
#include <srrg_system_utils/system_utils.h>
#include <srrg_messages/instances.h>

#include "DataPoint.hpp"

using namespace std;
using namespace srrg2_core;


namespace Loam{
  

  class SphericalDepthImage {
     protected:
       //this matrix is both the index matrix I and the spherical depth matrix D
       vector<vector< list< DataPoint >>> m_index_image;
       int m_num_vertical_rings;
       int m_num_points_ring;
       float m_min_elevation;
       float m_max_elevation;
       float m_epsilon_radius;
       float m_depth_differential_threshold;
       int m_min_neighboors_for_normal;
       int m_epsilon_times;
       PointNormalColor3fVectorCloud m_cloud;

     public:
      SphericalDepthImage()= default;

      SphericalDepthImage(
          int num_vertical_rings,
          int num_points_ring,
          float epsilon_radius,
          int epsilon_times,
          const PointNormalColor3fVectorCloud & cloud);

      ~SphericalDepthImage() = default;

      void buildIndexImage();
      void resetIndexImage();

      void removeFlatSurfaces();
      void markVerticalPoints();
      void removeNonVerticalPoints();
      void discoverBoundaryIndexes();

      bool expandBoundariesUp( DataPoint & t_starting_point,int & t_neighboors_count);
      bool expandBoundariesDown( DataPoint & t_starting_point,int & t_neighboors_count);
      bool expandBoundariesLeft( DataPoint & t_starting_point,int & t_neighboors_count);
      bool expandBoundariesRight( DataPoint & t_starting_point,int & t_neighboors_count);

      vector<int> mapSphericalCoordsInIndexImage(
          const float t_azimuth, const float t_elevation);

      vector<int> mapCartesianCoordsInIndexImage(
          const Vector3f & t_coords);
 
      static Vector2f extimateMinMaxElevation( const PointNormalColor3fVectorCloud & cloud);

      static  Vector3f directMappingFunc(const Vector3f & t_cart_coords);

      static  Vector3f inverseMappingFunc(const Vector3f & t_spher_coords);



      inline const vector<vector<list<DataPoint>>> & getIndexImage(){ return m_index_image;};

      inline void setIndexImage( const vector<vector<list<DataPoint>>> & t_indexImage){ m_index_image = t_indexImage;};

      inline const PointNormalColor3fVectorCloud & getPointCloud(){ return m_cloud;};

      inline void setPointCloud( const PointNormalColor3fVectorCloud & t_cloud){ m_cloud = t_cloud;};

      inline list<DataPoint> getListDataPointsAt( const int t_row, const int t_col){ return m_index_image[t_row][t_col];};
   };
}


