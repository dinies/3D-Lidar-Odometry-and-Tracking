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
include src/CMakeFiles/core.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/core.dir/flags.make

src/CMakeFiles/core.dir/Dummy.cpp.o: src/CMakeFiles/core.dir/flags.make
src/CMakeFiles/core.dir/Dummy.cpp.o: ../src/Dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dinies/gitrepos/loam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/core.dir/Dummy.cpp.o"
	cd /home/dinies/gitrepos/loam/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/core.dir/Dummy.cpp.o -c /home/dinies/gitrepos/loam/src/Dummy.cpp

src/CMakeFiles/core.dir/Dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/Dummy.cpp.i"
	cd /home/dinies/gitrepos/loam/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dinies/gitrepos/loam/src/Dummy.cpp > CMakeFiles/core.dir/Dummy.cpp.i

src/CMakeFiles/core.dir/Dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/Dummy.cpp.s"
	cd /home/dinies/gitrepos/loam/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dinies/gitrepos/loam/src/Dummy.cpp -o CMakeFiles/core.dir/Dummy.cpp.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/Dummy.cpp.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

../bin/libcore.a: src/CMakeFiles/core.dir/Dummy.cpp.o
../bin/libcore.a: src/CMakeFiles/core.dir/build.make
../bin/libcore.a: src/CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dinies/gitrepos/loam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../bin/libcore.a"
	cd /home/dinies/gitrepos/loam/build/src && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	cd /home/dinies/gitrepos/loam/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/core.dir/build: ../bin/libcore.a

.PHONY : src/CMakeFiles/core.dir/build

src/CMakeFiles/core.dir/clean:
	cd /home/dinies/gitrepos/loam/build/src && $(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/core.dir/clean

src/CMakeFiles/core.dir/depend:
	cd /home/dinies/gitrepos/loam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dinies/gitrepos/loam /home/dinies/gitrepos/loam/src /home/dinies/gitrepos/loam/build /home/dinies/gitrepos/loam/build/src /home/dinies/gitrepos/loam/build/src/CMakeFiles/core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/core.dir/depend

