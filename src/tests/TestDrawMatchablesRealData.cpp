#include <srrg_system_utils/parse_command_line.h>
#include <srrg_system_utils/system_utils.h>
#include <srrg_messages/instances.h>
#include <srrg_system_utils/shell_colors.h>

#include "loam/instances.h"
#include "loam/DatasetManager.hpp"
#include "loam/Visualizer.hpp"
#include "loam/features/SphericalDepthImage.hpp"
#include "loam/CustomMeasurementAdaptor.hpp"



using namespace srrg2_core;
using namespace srrg2_core_ros;
using namespace srrg2_qgl_viewport;
using namespace Loam;

const char* banner[] = {
    "dynamic executor",
      0
};


int main( int argc, char** argv){

  loam_registerTypes();
  messages_registerTypes();
  srrgInit( argc, argv, "hi");



  ParseCommandLine cmd_line(argv,banner);
  ArgumentString  dataset (&cmd_line, "d", "dataset", "path to dataset" , "");
  ArgumentString  epsilon_l(&cmd_line, "l", "epsilon_l", "parameter that defines epsilon_l" , "");
  ArgumentString  epsilon_dl(&cmd_line, "dl", "epsilon_dl", "parameter that defines epsilon_dl" , "");
  ArgumentString  epsilon_p(&cmd_line, "p", "epsilon_p", "parameter that defines epsilon_p" , "");
  ArgumentString  epsilon_dp(&cmd_line, "dp", "epsilon_dp", "parameter that defines epsilon_dp" , "");
  cmd_line.parse();




  const sphericalImage_params params(
    64, //num_vertical_rings
    768, //num_points_ring
    7, //epsilon_times
    0.15, //epsilon_radius
    2.1, //depth_differential_threshold
    7,  //min_neighboors_for_normal
    10, //epsilon_c
    1.5, //epsilon_d
    0.3, //epsilon_n
    std::stof( epsilon_l.value()), //epsilon_l
    std::stof( epsilon_dl.value()), //epsilon_dl
    std::stof( epsilon_p.value()), //epsilon_p
    std::stof( epsilon_dp.value())//epsilon_dp
  );

  DatasetManager dM(  dataset.value());
  BaseSensorMessagePtr cloudPtr_1 = dM.readPointerToMessageFromDataset();



  CustomMatchablefVectorData  matchables_1;
  CustomMeasurementAdaptorPtr measurementAdaptor =
    CustomMeasurementAdaptorPtr(new CustomMeasurementAdaptor);
  measurementAdaptor->setDest( &matchables_1);
  measurementAdaptor->setMeasurement( cloudPtr_1 );
  measurementAdaptor->compute();
  PointNormalColor3fVectorCloud  features_cloud = measurementAdaptor->drawMatchables();
  PointNormalColor3fVectorCloud  clusters_cloud = measurementAdaptor->drawClusters();


  messages_registerTypes();
  srrgInit( argc, argv, "hi");

  const float points_size = 2.0;
  QApplication qapp(argc, argv);
  ViewerCoreSharedQGL viewer(argc, argv, &qapp);

  ViewerCanvasPtr canvas1 = viewer.getCanvas("clusters");
  std::thread processing_thread1( Visualizer::visualizeCloud, canvas1, clusters_cloud, points_size);

  ViewerCanvasPtr canvas2 = viewer.getCanvas("matchables");
  std::thread processing_thread2( Visualizer::visualizeCloud, canvas2, features_cloud, points_size);

  viewer.startViewerServer();
  processing_thread1.join();
  processing_thread2.join();
  return 0;
}




