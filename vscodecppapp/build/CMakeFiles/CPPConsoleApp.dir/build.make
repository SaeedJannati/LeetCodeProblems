# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/saeed/projects/LeetCodeProblems/vscodecppapp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/saeed/projects/LeetCodeProblems/vscodecppapp/build

# Include any dependencies generated for this target.
include CMakeFiles/CPPConsoleApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CPPConsoleApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CPPConsoleApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPPConsoleApp.dir/flags.make

CMakeFiles/CPPConsoleApp.dir/main.cpp.o: CMakeFiles/CPPConsoleApp.dir/flags.make
CMakeFiles/CPPConsoleApp.dir/main.cpp.o: /home/saeed/projects/LeetCodeProblems/vscodecppapp/main.cpp
CMakeFiles/CPPConsoleApp.dir/main.cpp.o: CMakeFiles/CPPConsoleApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/saeed/projects/LeetCodeProblems/vscodecppapp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPPConsoleApp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CPPConsoleApp.dir/main.cpp.o -MF CMakeFiles/CPPConsoleApp.dir/main.cpp.o.d -o CMakeFiles/CPPConsoleApp.dir/main.cpp.o -c /home/saeed/projects/LeetCodeProblems/vscodecppapp/main.cpp

CMakeFiles/CPPConsoleApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CPPConsoleApp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/saeed/projects/LeetCodeProblems/vscodecppapp/main.cpp > CMakeFiles/CPPConsoleApp.dir/main.cpp.i

CMakeFiles/CPPConsoleApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CPPConsoleApp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/saeed/projects/LeetCodeProblems/vscodecppapp/main.cpp -o CMakeFiles/CPPConsoleApp.dir/main.cpp.s

# Object files for target CPPConsoleApp
CPPConsoleApp_OBJECTS = \
"CMakeFiles/CPPConsoleApp.dir/main.cpp.o"

# External object files for target CPPConsoleApp
CPPConsoleApp_EXTERNAL_OBJECTS =

CPPConsoleApp: CMakeFiles/CPPConsoleApp.dir/main.cpp.o
CPPConsoleApp: CMakeFiles/CPPConsoleApp.dir/build.make
CPPConsoleApp: CMakeFiles/CPPConsoleApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/saeed/projects/LeetCodeProblems/vscodecppapp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPPConsoleApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPPConsoleApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPPConsoleApp.dir/build: CPPConsoleApp
.PHONY : CMakeFiles/CPPConsoleApp.dir/build

CMakeFiles/CPPConsoleApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPPConsoleApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPPConsoleApp.dir/clean

CMakeFiles/CPPConsoleApp.dir/depend:
	cd /home/saeed/projects/LeetCodeProblems/vscodecppapp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/saeed/projects/LeetCodeProblems/vscodecppapp /home/saeed/projects/LeetCodeProblems/vscodecppapp /home/saeed/projects/LeetCodeProblems/vscodecppapp/build /home/saeed/projects/LeetCodeProblems/vscodecppapp/build /home/saeed/projects/LeetCodeProblems/vscodecppapp/build/CMakeFiles/CPPConsoleApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CPPConsoleApp.dir/depend

