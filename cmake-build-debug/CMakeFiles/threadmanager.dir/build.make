# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\jetbrains toolbox\apps\CLion\ch-0\203.5981.166\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\jetbrains toolbox\apps\CLion\ch-0\203.5981.166\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\jetbrains toolbox\project\OS_Project_X"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\jetbrains toolbox\project\OS_Project_X\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/threadmanager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/threadmanager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threadmanager.dir/flags.make

CMakeFiles/threadmanager.dir/threadmanager.cpp.obj: CMakeFiles/threadmanager.dir/flags.make
CMakeFiles/threadmanager.dir/threadmanager.cpp.obj: ../threadmanager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\jetbrains toolbox\project\OS_Project_X\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/threadmanager.dir/threadmanager.cpp.obj"
	D:\ming\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\threadmanager.dir\threadmanager.cpp.obj -c "D:\jetbrains toolbox\project\OS_Project_X\threadmanager.cpp"

CMakeFiles/threadmanager.dir/threadmanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/threadmanager.dir/threadmanager.cpp.i"
	D:\ming\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\jetbrains toolbox\project\OS_Project_X\threadmanager.cpp" > CMakeFiles\threadmanager.dir\threadmanager.cpp.i

CMakeFiles/threadmanager.dir/threadmanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/threadmanager.dir/threadmanager.cpp.s"
	D:\ming\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\jetbrains toolbox\project\OS_Project_X\threadmanager.cpp" -o CMakeFiles\threadmanager.dir\threadmanager.cpp.s

# Object files for target threadmanager
threadmanager_OBJECTS = \
"CMakeFiles/threadmanager.dir/threadmanager.cpp.obj"

# External object files for target threadmanager
threadmanager_EXTERNAL_OBJECTS =

threadmanager.exe: CMakeFiles/threadmanager.dir/threadmanager.cpp.obj
threadmanager.exe: CMakeFiles/threadmanager.dir/build.make
threadmanager.exe: CMakeFiles/threadmanager.dir/linklibs.rsp
threadmanager.exe: CMakeFiles/threadmanager.dir/objects1.rsp
threadmanager.exe: CMakeFiles/threadmanager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\jetbrains toolbox\project\OS_Project_X\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable threadmanager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\threadmanager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threadmanager.dir/build: threadmanager.exe

.PHONY : CMakeFiles/threadmanager.dir/build

CMakeFiles/threadmanager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\threadmanager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/threadmanager.dir/clean

CMakeFiles/threadmanager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\jetbrains toolbox\project\OS_Project_X" "D:\jetbrains toolbox\project\OS_Project_X" "D:\jetbrains toolbox\project\OS_Project_X\cmake-build-debug" "D:\jetbrains toolbox\project\OS_Project_X\cmake-build-debug" "D:\jetbrains toolbox\project\OS_Project_X\cmake-build-debug\CMakeFiles\threadmanager.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/threadmanager.dir/depend

