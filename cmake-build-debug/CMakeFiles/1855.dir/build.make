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
include CMakeFiles/1855.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1855.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1855.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1855.dir/flags.make

CMakeFiles/1855.dir/leetcode/1855.cpp.o: CMakeFiles/1855.dir/flags.make
CMakeFiles/1855.dir/leetcode/1855.cpp.o: /Users/sukilrelia/code/Algorithm/leetcode/1855.cpp
CMakeFiles/1855.dir/leetcode/1855.cpp.o: CMakeFiles/1855.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1855.dir/leetcode/1855.cpp.o"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1855.dir/leetcode/1855.cpp.o -MF CMakeFiles/1855.dir/leetcode/1855.cpp.o.d -o CMakeFiles/1855.dir/leetcode/1855.cpp.o -c /Users/sukilrelia/code/Algorithm/leetcode/1855.cpp

CMakeFiles/1855.dir/leetcode/1855.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1855.dir/leetcode/1855.cpp.i"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sukilrelia/code/Algorithm/leetcode/1855.cpp > CMakeFiles/1855.dir/leetcode/1855.cpp.i

CMakeFiles/1855.dir/leetcode/1855.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1855.dir/leetcode/1855.cpp.s"
	/opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sukilrelia/code/Algorithm/leetcode/1855.cpp -o CMakeFiles/1855.dir/leetcode/1855.cpp.s

# Object files for target 1855
1855_OBJECTS = \
"CMakeFiles/1855.dir/leetcode/1855.cpp.o"

# External object files for target 1855
1855_EXTERNAL_OBJECTS =

1855: CMakeFiles/1855.dir/leetcode/1855.cpp.o
1855: CMakeFiles/1855.dir/build.make
1855: CMakeFiles/1855.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1855"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1855.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1855.dir/build: 1855
.PHONY : CMakeFiles/1855.dir/build

CMakeFiles/1855.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1855.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1855.dir/clean

CMakeFiles/1855.dir/depend:
	cd /Users/sukilrelia/code/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sukilrelia/code/Algorithm /Users/sukilrelia/code/Algorithm /Users/sukilrelia/code/Algorithm/cmake-build-debug /Users/sukilrelia/code/Algorithm/cmake-build-debug /Users/sukilrelia/code/Algorithm/cmake-build-debug/CMakeFiles/1855.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1855.dir/depend

