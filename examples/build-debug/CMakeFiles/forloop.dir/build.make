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
include CMakeFiles/forloop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/forloop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forloop.dir/flags.make

CMakeFiles/forloop.dir/forloop.cpp.o: CMakeFiles/forloop.dir/flags.make
CMakeFiles/forloop.dir/forloop.cpp.o: ../forloop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olivier/code/Labs/ARPRO/examples/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/forloop.dir/forloop.cpp.o"
	/usr/bin/g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/forloop.dir/forloop.cpp.o -c /home/olivier/code/Labs/ARPRO/examples/forloop.cpp

CMakeFiles/forloop.dir/forloop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forloop.dir/forloop.cpp.i"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olivier/code/Labs/ARPRO/examples/forloop.cpp > CMakeFiles/forloop.dir/forloop.cpp.i

CMakeFiles/forloop.dir/forloop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forloop.dir/forloop.cpp.s"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olivier/code/Labs/ARPRO/examples/forloop.cpp -o CMakeFiles/forloop.dir/forloop.cpp.s

CMakeFiles/forloop.dir/forloop.cpp.o.requires:

.PHONY : CMakeFiles/forloop.dir/forloop.cpp.o.requires

CMakeFiles/forloop.dir/forloop.cpp.o.provides: CMakeFiles/forloop.dir/forloop.cpp.o.requires
	$(MAKE) -f CMakeFiles/forloop.dir/build.make CMakeFiles/forloop.dir/forloop.cpp.o.provides.build
.PHONY : CMakeFiles/forloop.dir/forloop.cpp.o.provides

CMakeFiles/forloop.dir/forloop.cpp.o.provides.build: CMakeFiles/forloop.dir/forloop.cpp.o


# Object files for target forloop
forloop_OBJECTS = \
"CMakeFiles/forloop.dir/forloop.cpp.o"

# External object files for target forloop
forloop_EXTERNAL_OBJECTS =

forloop: CMakeFiles/forloop.dir/forloop.cpp.o
forloop: CMakeFiles/forloop.dir/build.make
forloop: CMakeFiles/forloop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olivier/code/Labs/ARPRO/examples/build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable forloop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/forloop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/forloop.dir/build: forloop

.PHONY : CMakeFiles/forloop.dir/build

CMakeFiles/forloop.dir/requires: CMakeFiles/forloop.dir/forloop.cpp.o.requires

.PHONY : CMakeFiles/forloop.dir/requires

CMakeFiles/forloop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forloop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forloop.dir/clean

CMakeFiles/forloop.dir/depend:
	cd /home/olivier/code/Labs/ARPRO/examples/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olivier/code/Labs/ARPRO/examples /home/olivier/code/Labs/ARPRO/examples /home/olivier/code/Labs/ARPRO/examples/build-debug /home/olivier/code/Labs/ARPRO/examples/build-debug /home/olivier/code/Labs/ARPRO/examples/build-debug/CMakeFiles/forloop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/forloop.dir/depend

