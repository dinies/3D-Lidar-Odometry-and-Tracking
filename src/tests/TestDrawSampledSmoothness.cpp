#include "../loam/Visualizer.hpp"
using namespace srrg2_core;
using namespace srrg2_qgl_viewport;
using namespace Loam;


int main( int argc, char** argv){

  ViewerCoreSharedQGL viewer(argc, argv);
  ViewerCanvasPtr canvas = viewer.getCanvas("drawingSampleSmoothness");
  std::thread processing_thread(Visualizer::drawingSampledSmoothness, canvas );
  viewer.startViewerServer();
  processing_thread.join();
  return 0;
}

