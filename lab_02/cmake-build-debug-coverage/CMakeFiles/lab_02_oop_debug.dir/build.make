# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/denis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/denis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denis/OOP/lab_02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denis/OOP/lab_02/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/lab_02_oop_debug.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab_02_oop_debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab_02_oop_debug.dir/flags.make

CMakeFiles/lab_02_oop_debug.dir/main.cpp.o: CMakeFiles/lab_02_oop_debug.dir/flags.make
CMakeFiles/lab_02_oop_debug.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/OOP/lab_02/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab_02_oop_debug.dir/main.cpp.o"
	/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab_02_oop_debug.dir/main.cpp.o -c /home/denis/OOP/lab_02/main.cpp

CMakeFiles/lab_02_oop_debug.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab_02_oop_debug.dir/main.cpp.i"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/OOP/lab_02/main.cpp > CMakeFiles/lab_02_oop_debug.dir/main.cpp.i

CMakeFiles/lab_02_oop_debug.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab_02_oop_debug.dir/main.cpp.s"
	/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/OOP/lab_02/main.cpp -o CMakeFiles/lab_02_oop_debug.dir/main.cpp.s

# Object files for target lab_02_oop_debug
lab_02_oop_debug_OBJECTS = \
"CMakeFiles/lab_02_oop_debug.dir/main.cpp.o"

# External object files for target lab_02_oop_debug
lab_02_oop_debug_EXTERNAL_OBJECTS =

lab_02_oop_debug: CMakeFiles/lab_02_oop_debug.dir/main.cpp.o
lab_02_oop_debug: CMakeFiles/lab_02_oop_debug.dir/build.make
lab_02_oop_debug: liblab_02_oop.a
lab_02_oop_debug: CMakeFiles/lab_02_oop_debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denis/OOP/lab_02/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab_02_oop_debug"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab_02_oop_debug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab_02_oop_debug.dir/build: lab_02_oop_debug

.PHONY : CMakeFiles/lab_02_oop_debug.dir/build

CMakeFiles/lab_02_oop_debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab_02_oop_debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab_02_oop_debug.dir/clean

CMakeFiles/lab_02_oop_debug.dir/depend:
	cd /home/denis/OOP/lab_02/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denis/OOP/lab_02 /home/denis/OOP/lab_02 /home/denis/OOP/lab_02/cmake-build-debug-coverage /home/denis/OOP/lab_02/cmake-build-debug-coverage /home/denis/OOP/lab_02/cmake-build-debug-coverage/CMakeFiles/lab_02_oop_debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab_02_oop_debug.dir/depend

