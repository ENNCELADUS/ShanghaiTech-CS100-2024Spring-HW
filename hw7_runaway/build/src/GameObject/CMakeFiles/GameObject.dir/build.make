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
include src/GameObject/CMakeFiles/GameObject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.make

# Include the progress variables for this target.
include src/GameObject/CMakeFiles/GameObject.dir/progress.make

# Include the compile flags for this target's objects.
include src/GameObject/CMakeFiles/GameObject.dir/flags.make

src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/flags.make
src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameObject/GameObject.cpp
src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj -MF CMakeFiles\GameObject.dir\GameObject.cpp.obj.d -o CMakeFiles\GameObject.dir\GameObject.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\GameObject.cpp

src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameObject.dir/GameObject.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\GameObject.cpp > CMakeFiles\GameObject.dir\GameObject.cpp.i

src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameObject.dir/GameObject.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\GameObject.cpp -o CMakeFiles\GameObject.dir\GameObject.cpp.s

src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/flags.make
src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameObject/Background.cpp
src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj -MF CMakeFiles\GameObject.dir\Background.cpp.obj.d -o CMakeFiles\GameObject.dir\Background.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Background.cpp

src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameObject.dir/Background.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Background.cpp > CMakeFiles\GameObject.dir\Background.cpp.i

src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameObject.dir/Background.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Background.cpp -o CMakeFiles\GameObject.dir\Background.cpp.s

src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/flags.make
src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameObject/Player.cpp
src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj -MF CMakeFiles\GameObject.dir\Player.cpp.obj.d -o CMakeFiles\GameObject.dir\Player.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Player.cpp

src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameObject.dir/Player.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Player.cpp > CMakeFiles\GameObject.dir\Player.cpp.i

src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameObject.dir/Player.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Player.cpp -o CMakeFiles\GameObject.dir\Player.cpp.s

src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/flags.make
src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameObject/Enemies.cpp
src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj -MF CMakeFiles\GameObject.dir\Enemies.cpp.obj.d -o CMakeFiles\GameObject.dir\Enemies.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Enemies.cpp

src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameObject.dir/Enemies.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Enemies.cpp > CMakeFiles\GameObject.dir\Enemies.cpp.i

src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameObject.dir/Enemies.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Enemies.cpp -o CMakeFiles\GameObject.dir\Enemies.cpp.s

src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/flags.make
src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameObject/Bullet.cpp
src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj -MF CMakeFiles\GameObject.dir\Bullet.cpp.obj.d -o CMakeFiles\GameObject.dir\Bullet.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Bullet.cpp

src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameObject.dir/Bullet.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Bullet.cpp > CMakeFiles\GameObject.dir\Bullet.cpp.i

src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameObject.dir/Bullet.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Bullet.cpp -o CMakeFiles\GameObject.dir\Bullet.cpp.s

src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/flags.make
src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw7_runaway/src/GameObject/Axe.cpp
src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj: src/GameObject/CMakeFiles/GameObject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj -MF CMakeFiles\GameObject.dir\Axe.cpp.obj.d -o CMakeFiles\GameObject.dir\Axe.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Axe.cpp

src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GameObject.dir/Axe.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Axe.cpp > CMakeFiles\GameObject.dir\Axe.cpp.i

src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GameObject.dir/Axe.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject\Axe.cpp -o CMakeFiles\GameObject.dir\Axe.cpp.s

# Object files for target GameObject
GameObject_OBJECTS = \
"CMakeFiles/GameObject.dir/GameObject.cpp.obj" \
"CMakeFiles/GameObject.dir/Background.cpp.obj" \
"CMakeFiles/GameObject.dir/Player.cpp.obj" \
"CMakeFiles/GameObject.dir/Enemies.cpp.obj" \
"CMakeFiles/GameObject.dir/Bullet.cpp.obj" \
"CMakeFiles/GameObject.dir/Axe.cpp.obj"

# External object files for target GameObject
GameObject_EXTERNAL_OBJECTS =

lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/GameObject.cpp.obj
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/Background.cpp.obj
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/Player.cpp.obj
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/Enemies.cpp.obj
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/Bullet.cpp.obj
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/Axe.cpp.obj
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/build.make
lib/libGameObject.a: src/GameObject/CMakeFiles/GameObject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ..\..\lib\libGameObject.a"
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && $(CMAKE_COMMAND) -P CMakeFiles\GameObject.dir\cmake_clean_target.cmake
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GameObject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GameObject/CMakeFiles/GameObject.dir/build: lib/libGameObject.a
.PHONY : src/GameObject/CMakeFiles/GameObject.dir/build

src/GameObject/CMakeFiles/GameObject.dir/clean:
	cd /d E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject && $(CMAKE_COMMAND) -P CMakeFiles\GameObject.dir\cmake_clean.cmake
.PHONY : src/GameObject/CMakeFiles/GameObject.dir/clean

src/GameObject/CMakeFiles/GameObject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\RICHARD\CS100\CS100-HW\hw7_runaway E:\RICHARD\CS100\CS100-HW\hw7_runaway\src\GameObject E:\RICHARD\CS100\CS100-HW\hw7_runaway\build E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject E:\RICHARD\CS100\CS100-HW\hw7_runaway\build\src\GameObject\CMakeFiles\GameObject.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/GameObject/CMakeFiles/GameObject.dir/depend

