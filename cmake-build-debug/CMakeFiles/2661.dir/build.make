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
include CMakeFiles/2661.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/2661.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/2661.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2661.dir/flags.make

CMakeFiles/2661.dir/leetcode/2661.cpp.o: CMakeFiles/2661.dir/flags.make
CMakeFiles/2661.dir/leetcode/2661.cpp.o: /Users/sukilrelia/code/Algorithm/leetcode/2661.cpp
CMakeFiles/2661.dir/leetcode/2661.cpp.o: CMakeFiles/2661.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2661.dir/leetcode/2661.cpp.o"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2661.dir/leetcode/2661.cpp.o -MF CMakeFiles/2661.dir/leetcode/2661.cpp.o.d -o CMakeFiles/2661.dir/leetcode/2661.cpp.o -c /Users/sukilrelia/code/Algorithm/leetcode/2661.cpp

CMakeFiles/2661.dir/leetcode/2661.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2661.dir/leetcode/2661.cpp.i"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sukilrelia/code/Algorithm/leetcode/2661.cpp > CMakeFiles/2661.dir/leetcode/2661.cpp.i

CMakeFiles/2661.dir/leetcode/2661.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2661.dir/leetcode/2661.cpp.s"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sukilrelia/code/Algorithm/leetcode/2661.cpp -o CMakeFiles/2661.dir/leetcode/2661.cpp.s

# Object files for target 2661
2661_OBJECTS = \
"CMakeFiles/2661.dir/leetcode/2661.cpp.o"

# External object files for target 2661
2661_EXTERNAL_OBJECTS =

2661: CMakeFiles/2661.dir/leetcode/2661.cpp.o
2661: CMakeFiles/2661.dir/build.make
2661: CMakeFiles/2661.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2661"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2661.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2661.dir/build: 2661
.PHONY : CMakeFiles/2661.dir/build

CMakeFiles/2661.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2661.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2661.dir/clean

CMakeFiles/2661.dir/depend:
	cd /Users/sukilrelia/code/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sukilrelia/code/Algorithm /Users/sukilrelia/code/Algorithm /Users/sukilrelia/code/Algorithm/cmake-build-debug /Users/sukilrelia/code/Algorithm/cmake-build-debug /Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles/2661.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2661.dir/depend
