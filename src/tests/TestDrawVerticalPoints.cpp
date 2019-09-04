#include "../loam/Visualizer.hpp"

using namespace srrg2_core;
using namespace srrg2_qgl_viewport;
using namespace Loam;


int main( int argc, char** argv){

  string filename = "/home/dinies/temp/trial/tuttty.boss";
  
  QApplication qapp(argc, argv);
  ViewerCoreSharedQGL viewer(argc, argv, &qapp);
  ViewerCanvasPtr canvas1 = viewer.getCanvas("cleanedScene");
  ViewerCanvasPtr canvas2 = viewer.getCanvas("rawScene");
  std::thread processing_thread(
      Visualizer::visualizeCleanedClouds,canvas1,canvas2,filename);
  viewer.startViewerServer();
  processing_thread.join();
  return 0;
}




