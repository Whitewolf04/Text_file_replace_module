# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C_learning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C_learning\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C_learning.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/C_learning.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C_learning.dir/flags.make

CMakeFiles/C_learning.dir/A1.c.obj: CMakeFiles/C_learning.dir/flags.make
CMakeFiles/C_learning.dir/A1.c.obj: ../A1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C_learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C_learning.dir/A1.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C_learning.dir\A1.c.obj -c D:\C_learning\A1.c

CMakeFiles/C_learning.dir/A1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C_learning.dir/A1.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C_learning\A1.c > CMakeFiles\C_learning.dir\A1.c.i

CMakeFiles/C_learning.dir/A1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C_learning.dir/A1.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C_learning\A1.c -o CMakeFiles\C_learning.dir\A1.c.s

CMakeFiles/C_learning.dir/text.c.obj: CMakeFiles/C_learning.dir/flags.make
CMakeFiles/C_learning.dir/text.c.obj: ../text.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C_learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/C_learning.dir/text.c.obj"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\C_learning.dir\text.c.obj -c D:\C_learning\text.c

CMakeFiles/C_learning.dir/text.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C_learning.dir/text.c.i"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C_learning\text.c > CMakeFiles\C_learning.dir\text.c.i

CMakeFiles/C_learning.dir/text.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C_learning.dir/text.c.s"
	C:\msys64\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C_learning\text.c -o CMakeFiles\C_learning.dir\text.c.s

# Object files for target C_learning
C_learning_OBJECTS = \
"CMakeFiles/C_learning.dir/A1.c.obj" \
"CMakeFiles/C_learning.dir/text.c.obj"

# External object files for target C_learning
C_learning_EXTERNAL_OBJECTS =

C_learning.exe: CMakeFiles/C_learning.dir/A1.c.obj
C_learning.exe: CMakeFiles/C_learning.dir/text.c.obj
C_learning.exe: CMakeFiles/C_learning.dir/build.make
C_learning.exe: CMakeFiles/C_learning.dir/linklibs.rsp
C_learning.exe: CMakeFiles/C_learning.dir/objects1.rsp
C_learning.exe: CMakeFiles/C_learning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C_learning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable C_learning.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C_learning.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C_learning.dir/build: C_learning.exe
.PHONY : CMakeFiles/C_learning.dir/build

CMakeFiles/C_learning.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C_learning.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C_learning.dir/clean

CMakeFiles/C_learning.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C_learning D:\C_learning D:\C_learning\cmake-build-debug D:\C_learning\cmake-build-debug D:\C_learning\cmake-build-debug\CMakeFiles\C_learning.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C_learning.dir/depend

