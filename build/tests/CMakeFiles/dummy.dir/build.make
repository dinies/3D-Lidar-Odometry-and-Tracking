# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dinies/gitrepos/loam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dinies/gitrepos/loam/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/dummy.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/dummy.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/dummy.dir/flags.make

tests/CMakeFiles/dummy.dir/Starter.cpp.o: tests/CMakeFiles/dummy.dir/flags.make
tests/CMakeFiles/dummy.dir/Starter.cpp.o: ../tests/Starter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dinies/gitrepos/loam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/dummy.dir/Starter.cpp.o"
	cd /home/dinies/gitrepos/loam/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dummy.dir/Starter.cpp.o -c /home/dinies/gitrepos/loam/tests/Starter.cpp

tests/CMakeFiles/dummy.dir/Starter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dummy.dir/Starter.cpp.i"
	cd /home/dinies/gitrepos/loam/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dinies/gitrepos/loam/tests/Starter.cpp > CMakeFiles/dummy.dir/Starter.cpp.i

tests/CMakeFiles/dummy.dir/Starter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dummy.dir/Starter.cpp.s"
	cd /home/dinies/gitrepos/loam/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dinies/gitrepos/loam/tests/Starter.cpp -o CMakeFiles/dummy.dir/Starter.cpp.s

tests/CMakeFiles/dummy.dir/TestDummy.cpp.o: tests/CMakeFiles/dummy.dir/flags.make
tests/CMakeFiles/dummy.dir/TestDummy.cpp.o: ../tests/TestDummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dinies/gitrepos/loam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/dummy.dir/TestDummy.cpp.o"
	cd /home/dinies/gitrepos/loam/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dummy.dir/TestDummy.cpp.o -c /home/dinies/gitrepos/loam/tests/TestDummy.cpp

tests/CMakeFiles/dummy.dir/TestDummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dummy.dir/TestDummy.cpp.i"
	cd /home/dinies/gitrepos/loam/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dinies/gitrepos/loam/tests/TestDummy.cpp > CMakeFiles/dummy.dir/TestDummy.cpp.i

tests/CMakeFiles/dummy.dir/TestDummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dummy.dir/TestDummy.cpp.s"
	cd /home/dinies/gitrepos/loam/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dinies/gitrepos/loam/tests/TestDummy.cpp -o CMakeFiles/dummy.dir/TestDummy.cpp.s

# Object files for target dummy
dummy_OBJECTS = \
"CMakeFiles/dummy.dir/Starter.cpp.o" \
"CMakeFiles/dummy.dir/TestDummy.cpp.o"

# External object files for target dummy
dummy_EXTERNAL_OBJECTS =

../bin/dummy: tests/CMakeFiles/dummy.dir/Starter.cpp.o
../bin/dummy: tests/CMakeFiles/dummy.dir/TestDummy.cpp.o
../bin/dummy: tests/CMakeFiles/dummy.dir/build.make
../bin/dummy: lib/libgtest_maind.a
../bin/dummy: lib/libgmock_maind.a
../bin/dummy: ../bin/libcore.a
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
../bin/dummy: lib/libgmockd.a
../bin/dummy: lib/libgtestd.a
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
../bin/dummy: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
../bin/dummy: tests/CMakeFiles/dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dinies/gitrepos/loam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../../bin/dummy"
	cd /home/dinies/gitrepos/loam/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/dummy.dir/build: ../bin/dummy

.PHONY : tests/CMakeFiles/dummy.dir/build

tests/CMakeFiles/dummy.dir/clean:
	cd /home/dinies/gitrepos/loam/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/dummy.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/dummy.dir/clean

tests/CMakeFiles/dummy.dir/depend:
	cd /home/dinies/gitrepos/loam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dinies/gitrepos/loam /home/dinies/gitrepos/loam/tests /home/dinies/gitrepos/loam/build /home/dinies/gitrepos/loam/build/tests /home/dinies/gitrepos/loam/build/tests/CMakeFiles/dummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/dummy.dir/depend

