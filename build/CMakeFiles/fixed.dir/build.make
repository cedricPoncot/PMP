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
include CMakeFiles/fixed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fixed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fixed.dir/flags.make

CMakeFiles/fixed.dir/fixed.cc.o: CMakeFiles/fixed.dir/flags.make
CMakeFiles/fixed.dir/fixed.cc.o: ../fixed.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/PMP/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fixed.dir/fixed.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fixed.dir/fixed.cc.o -c /home/user/Documents/PMP/Projet/fixed.cc

CMakeFiles/fixed.dir/fixed.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fixed.dir/fixed.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/PMP/Projet/fixed.cc > CMakeFiles/fixed.dir/fixed.cc.i

CMakeFiles/fixed.dir/fixed.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fixed.dir/fixed.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/PMP/Projet/fixed.cc -o CMakeFiles/fixed.dir/fixed.cc.s

CMakeFiles/fixed.dir/fixed.cc.o.requires:

.PHONY : CMakeFiles/fixed.dir/fixed.cc.o.requires

CMakeFiles/fixed.dir/fixed.cc.o.provides: CMakeFiles/fixed.dir/fixed.cc.o.requires
	$(MAKE) -f CMakeFiles/fixed.dir/build.make CMakeFiles/fixed.dir/fixed.cc.o.provides.build
.PHONY : CMakeFiles/fixed.dir/fixed.cc.o.provides

CMakeFiles/fixed.dir/fixed.cc.o.provides.build: CMakeFiles/fixed.dir/fixed.cc.o


CMakeFiles/fixed.dir/fp.cc.o: CMakeFiles/fixed.dir/flags.make
CMakeFiles/fixed.dir/fp.cc.o: ../fp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Documents/PMP/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fixed.dir/fp.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fixed.dir/fp.cc.o -c /home/user/Documents/PMP/Projet/fp.cc

CMakeFiles/fixed.dir/fp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fixed.dir/fp.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Documents/PMP/Projet/fp.cc > CMakeFiles/fixed.dir/fp.cc.i

CMakeFiles/fixed.dir/fp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fixed.dir/fp.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Documents/PMP/Projet/fp.cc -o CMakeFiles/fixed.dir/fp.cc.s

CMakeFiles/fixed.dir/fp.cc.o.requires:

.PHONY : CMakeFiles/fixed.dir/fp.cc.o.requires

CMakeFiles/fixed.dir/fp.cc.o.provides: CMakeFiles/fixed.dir/fp.cc.o.requires
	$(MAKE) -f CMakeFiles/fixed.dir/build.make CMakeFiles/fixed.dir/fp.cc.o.provides.build
.PHONY : CMakeFiles/fixed.dir/fp.cc.o.provides

CMakeFiles/fixed.dir/fp.cc.o.provides.build: CMakeFiles/fixed.dir/fp.cc.o


# Object files for target fixed
fixed_OBJECTS = \
"CMakeFiles/fixed.dir/fixed.cc.o" \
"CMakeFiles/fixed.dir/fp.cc.o"

# External object files for target fixed
fixed_EXTERNAL_OBJECTS =

fixed: CMakeFiles/fixed.dir/fixed.cc.o
fixed: CMakeFiles/fixed.dir/fp.cc.o
fixed: CMakeFiles/fixed.dir/build.make
fixed: CMakeFiles/fixed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Documents/PMP/Projet/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable fixed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fixed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fixed.dir/build: fixed

.PHONY : CMakeFiles/fixed.dir/build

CMakeFiles/fixed.dir/requires: CMakeFiles/fixed.dir/fixed.cc.o.requires
CMakeFiles/fixed.dir/requires: CMakeFiles/fixed.dir/fp.cc.o.requires

.PHONY : CMakeFiles/fixed.dir/requires

CMakeFiles/fixed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fixed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fixed.dir/clean

CMakeFiles/fixed.dir/depend:
	cd /home/user/Documents/PMP/Projet/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Documents/PMP/Projet /home/user/Documents/PMP/Projet /home/user/Documents/PMP/Projet/build /home/user/Documents/PMP/Projet/build /home/user/Documents/PMP/Projet/build/CMakeFiles/fixed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fixed.dir/depend
