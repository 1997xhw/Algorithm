# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sukilrelia/code/Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sukilrelia/code/Algorithm/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1457.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1457.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1457.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1457.dir/flags.make

CMakeFiles/1457.dir/leetcode/1457.cpp.o: CMakeFiles/1457.dir/flags.make
CMakeFiles/1457.dir/leetcode/1457.cpp.o: /Users/sukilrelia/code/Algorithm/leetcode/1457.cpp
CMakeFiles/1457.dir/leetcode/1457.cpp.o: CMakeFiles/1457.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1457.dir/leetcode/1457.cpp.o"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1457.dir/leetcode/1457.cpp.o -MF CMakeFiles/1457.dir/leetcode/1457.cpp.o.d -o CMakeFiles/1457.dir/leetcode/1457.cpp.o -c /Users/sukilrelia/code/Algorithm/leetcode/1457.cpp

CMakeFiles/1457.dir/leetcode/1457.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1457.dir/leetcode/1457.cpp.i"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sukilrelia/code/Algorithm/leetcode/1457.cpp > CMakeFiles/1457.dir/leetcode/1457.cpp.i

CMakeFiles/1457.dir/leetcode/1457.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1457.dir/leetcode/1457.cpp.s"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sukilrelia/code/Algorithm/leetcode/1457.cpp -o CMakeFiles/1457.dir/leetcode/1457.cpp.s

# Object files for target 1457
1457_OBJECTS = \
"CMakeFiles/1457.dir/leetcode/1457.cpp.o"

# External object files for target 1457
1457_EXTERNAL_OBJECTS =

1457: CMakeFiles/1457.dir/leetcode/1457.cpp.o
1457: CMakeFiles/1457.dir/build.make
1457: CMakeFiles/1457.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1457"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1457.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1457.dir/build: 1457
.PHONY : CMakeFiles/1457.dir/build

CMakeFiles/1457.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1457.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1457.dir/clean

CMakeFiles/1457.dir/depend:
	cd /Users/sukilrelia/code/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sukilrelia/code/Algorithm /Users/sukilrelia/code/Algorithm /Users/sukilrelia/code/Algorithm/cmake-build-debug /Users/sukilrelia/code/Algorithm/cmake-build-debug /Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles/1457.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1457.dir/depend
