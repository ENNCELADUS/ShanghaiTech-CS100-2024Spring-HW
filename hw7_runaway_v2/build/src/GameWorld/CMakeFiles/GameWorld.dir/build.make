# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\RICHARD\CS100\CS100-HW\hw7_runaway

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\RICHARD\CS100\CS100-HW\hw7_runaway\build

# Include any dependencies generated for this target.
include src/GameWorld/CMakeFiles/GameWorld.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/GameWorld/CMakeFiles/GameWorld.dir/compiler_depend.make

# Include the progress variables for this target.
include src/GameWorld/CMakeFiles/GameWorld.dir/progress.make

# Include the compile flags for this target's objects.
include src/GameWorld/CMakeFiles/GameWorld.dir/flags.make

src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj: src/GameWorld/CMakeFiles/GameWorld.dir/flags.make
src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj: src/GameWorld/CMakeFiles/GameWorld.dir/includes_CXX.rsp
src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameWorld/GameWorld.cpp
src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj: src/GameWorld/CMakeFiles/GameWorld.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj -MF CMakeFiles\GameWorld.dir\GameWorld.cpp.obj.d -o CMakeFiles\GameWorld.dir\GameWorld.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameWorld\GameWorld.cpp

src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameWorld.dir/GameWorld.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameWorld\GameWorld.cpp > CMakeFiles\GameWorld.dir\GameWorld.cpp.i

src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameWorld.dir/GameWorld.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameWorld\GameWorld.cpp -o CMakeFiles\GameWorld.dir\GameWorld.cpp.s

# Object files for target GameWorld
GameWorld_OBJECTS = \
"CMakeFiles/GameWorld.dir/GameWorld.cpp.obj"

# External object files for target GameWorld
GameWorld_EXTERNAL_OBJECTS =

lib/libGameWorld.a: src/GameWorld/CMakeFiles/GameWorld.dir/GameWorld.cpp.obj
lib/libGameWorld.a: src/GameWorld/CMakeFiles/GameWorld.dir/build.make
lib/libGameWorld.a: src/GameWorld/CMakeFiles/GameWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\lib\libGameWorld.a"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld && $(CMAKE_COMMAND) -P CMakeFiles\GameWorld.dir\cmake_clean_target.cmake
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GameWorld.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GameWorld/CMakeFiles/GameWorld.dir/build: lib/libGameWorld.a
.PHONY : src/GameWorld/CMakeFiles/GameWorld.dir/build

src/GameWorld/CMakeFiles/GameWorld.dir/clean:
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld && $(CMAKE_COMMAND) -P CMakeFiles\GameWorld.dir\cmake_clean.cmake
.PHONY : src/GameWorld/CMakeFiles/GameWorld.dir/clean

src/GameWorld/CMakeFiles/GameWorld.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\RICHARD\CS100\CS100-HW\hw7_runaway E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameWorld E:\RICHARD\CS100\CS100-HW\hw7_runaway\build E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameWorld\CMakeFiles\GameWorld.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/GameWorld/CMakeFiles/GameWorld.dir/depend

