# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/olivier/code/Labs/ARPRO/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olivier/code/Labs/ARPRO/examples/build-debug

# Include any dependencies generated for this target.
include CMakeFiles/thr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/thr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thr.dir/flags.make

CMakeFiles/thr.dir/thr.cpp.o: CMakeFiles/thr.dir/flags.make
CMakeFiles/thr.dir/thr.cpp.o: ../thr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olivier/code/Labs/ARPRO/examples/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thr.dir/thr.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/thr.dir/thr.cpp.o -c /home/olivier/code/Labs/ARPRO/examples/thr.cpp

CMakeFiles/thr.dir/thr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thr.dir/thr.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olivier/code/Labs/ARPRO/examples/thr.cpp > CMakeFiles/thr.dir/thr.cpp.i

CMakeFiles/thr.dir/thr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thr.dir/thr.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olivier/code/Labs/ARPRO/examples/thr.cpp -o CMakeFiles/thr.dir/thr.cpp.s

CMakeFiles/thr.dir/thr.cpp.o.requires:

.PHONY : CMakeFiles/thr.dir/thr.cpp.o.requires

CMakeFiles/thr.dir/thr.cpp.o.provides: CMakeFiles/thr.dir/thr.cpp.o.requires
	$(MAKE) -f CMakeFiles/thr.dir/build.make CMakeFiles/thr.dir/thr.cpp.o.provides.build
.PHONY : CMakeFiles/thr.dir/thr.cpp.o.provides

CMakeFiles/thr.dir/thr.cpp.o.provides.build: CMakeFiles/thr.dir/thr.cpp.o


# Object files for target thr
thr_OBJECTS = \
"CMakeFiles/thr.dir/thr.cpp.o"

# External object files for target thr
thr_EXTERNAL_OBJECTS =

thr: CMakeFiles/thr.dir/thr.cpp.o
thr: CMakeFiles/thr.dir/build.make
thr: CMakeFiles/thr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olivier/code/Labs/ARPRO/examples/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thr.dir/build: thr

.PHONY : CMakeFiles/thr.dir/build

CMakeFiles/thr.dir/requires: CMakeFiles/thr.dir/thr.cpp.o.requires

.PHONY : CMakeFiles/thr.dir/requires

CMakeFiles/thr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thr.dir/clean

CMakeFiles/thr.dir/depend:
	cd /home/olivier/code/Labs/ARPRO/examples/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/code/Labs/ARPRO/examples /home/olivier/code/Labs/ARPRO/examples /home/olivier/code/Labs/ARPRO/examples/build-debug /home/olivier/code/Labs/ARPRO/examples/build-debug /home/olivier/code/Labs/ARPRO/examples/build-debug/CMakeFiles/thr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thr.dir/depend

