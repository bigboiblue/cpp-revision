# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/multithreading.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/multithreading.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/multithreading.dir/flags.make

CMakeFiles/multithreading.dir/main.cpp.o: CMakeFiles/multithreading.dir/flags.make
CMakeFiles/multithreading.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/multithreading.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/multithreading.dir/main.cpp.o -c "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/main.cpp"

CMakeFiles/multithreading.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/multithreading.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/main.cpp" > CMakeFiles/multithreading.dir/main.cpp.i

CMakeFiles/multithreading.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/multithreading.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/main.cpp" -o CMakeFiles/multithreading.dir/main.cpp.s

# Object files for target multithreading
multithreading_OBJECTS = \
"CMakeFiles/multithreading.dir/main.cpp.o"

# External object files for target multithreading
multithreading_EXTERNAL_OBJECTS =

multithreading: CMakeFiles/multithreading.dir/main.cpp.o
multithreading: CMakeFiles/multithreading.dir/build.make
multithreading: CMakeFiles/multithreading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable multithreading"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/multithreading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/multithreading.dir/build: multithreading

.PHONY : CMakeFiles/multithreading.dir/build

CMakeFiles/multithreading.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/multithreading.dir/cmake_clean.cmake
.PHONY : CMakeFiles/multithreading.dir/clean

CMakeFiles/multithreading.dir/depend:
	cd "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading" "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading" "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug" "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug" "/home/kyle/Documents/Workspace/C++/1. Revision/multithreading/cmake-build-debug/CMakeFiles/multithreading.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/multithreading.dir/depend

