# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/user/Documents/PMP/Projet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Documents/PMP/Projet/build

# Include any dependencies generated for this target.
include CMakeFiles/testfixed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testfixed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testfixed.dir/flags.make

CMakeFiles/testfixed.dir/testfixed.cc.o: CMakeFiles/testfixed.dir/flags.make
CMakeFiles/testfixed.dir/testfixed.cc.o: ../testfixed.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/PMP/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testfixed.dir/testfixed.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testfixed.dir/testfixed.cc.o -c /home/user/Documents/PMP/Projet/testfixed.cc

CMakeFiles/testfixed.dir/testfixed.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testfixed.dir/testfixed.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/PMP/Projet/testfixed.cc > CMakeFiles/testfixed.dir/testfixed.cc.i

CMakeFiles/testfixed.dir/testfixed.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testfixed.dir/testfixed.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/PMP/Projet/testfixed.cc -o CMakeFiles/testfixed.dir/testfixed.cc.s

CMakeFiles/testfixed.dir/testfixed.cc.o.requires:

.PHONY : CMakeFiles/testfixed.dir/testfixed.cc.o.requires

CMakeFiles/testfixed.dir/testfixed.cc.o.provides: CMakeFiles/testfixed.dir/testfixed.cc.o.requires
	$(MAKE) -f CMakeFiles/testfixed.dir/build.make CMakeFiles/testfixed.dir/testfixed.cc.o.provides.build
.PHONY : CMakeFiles/testfixed.dir/testfixed.cc.o.provides

CMakeFiles/testfixed.dir/testfixed.cc.o.provides.build: CMakeFiles/testfixed.dir/testfixed.cc.o


CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o: CMakeFiles/testfixed.dir/flags.make
CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o: ../googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/PMP/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o -c /home/user/Documents/PMP/Projet/googletest/googletest/src/gtest-all.cc

CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/PMP/Projet/googletest/googletest/src/gtest-all.cc > CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.i

CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/PMP/Projet/googletest/googletest/src/gtest-all.cc -o CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.s

CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.requires:

.PHONY : CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.requires

CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.provides: CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f CMakeFiles/testfixed.dir/build.make CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.provides.build
.PHONY : CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.provides

CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.provides.build: CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o


# Object files for target testfixed
testfixed_OBJECTS = \
"CMakeFiles/testfixed.dir/testfixed.cc.o" \
"CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o"

# External object files for target testfixed
testfixed_EXTERNAL_OBJECTS =

testfixed: CMakeFiles/testfixed.dir/testfixed.cc.o
testfixed: CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o
testfixed: CMakeFiles/testfixed.dir/build.make
testfixed: CMakeFiles/testfixed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Documents/PMP/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testfixed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testfixed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testfixed.dir/build: testfixed

.PHONY : CMakeFiles/testfixed.dir/build

CMakeFiles/testfixed.dir/requires: CMakeFiles/testfixed.dir/testfixed.cc.o.requires
CMakeFiles/testfixed.dir/requires: CMakeFiles/testfixed.dir/googletest/googletest/src/gtest-all.cc.o.requires

.PHONY : CMakeFiles/testfixed.dir/requires

CMakeFiles/testfixed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testfixed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testfixed.dir/clean

CMakeFiles/testfixed.dir/depend:
	cd /home/user/Documents/PMP/Projet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/PMP/Projet /home/user/Documents/PMP/Projet /home/user/Documents/PMP/Projet/build /home/user/Documents/PMP/Projet/build /home/user/Documents/PMP/Projet/build/CMakeFiles/testfixed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testfixed.dir/depend
