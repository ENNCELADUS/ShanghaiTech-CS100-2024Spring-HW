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
CMAKE_SOURCE_DIR = E:\RICHARD\CS100\CS100-HW\hw8\attachments

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\RICHARD\CS100\CS100-HW\hw8\attachments\build

# Include any dependencies generated for this target.
include src/GameObject/CMakeFiles/SeedButton.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/GameObject/CMakeFiles/SeedButton.dir/compiler_depend.make

# Include the progress variables for this target.
include src/GameObject/CMakeFiles/SeedButton.dir/progress.make

# Include the compile flags for this target's objects.
include src/GameObject/CMakeFiles/SeedButton.dir/flags.make

src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj: src/GameObject/CMakeFiles/SeedButton.dir/flags.make
src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj: src/GameObject/CMakeFiles/SeedButton.dir/includes_CXX.rsp
src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj: E:/RICHARD/CS100/CS100-HW/hw8/attachments/src/GameObject/SeedButton.cpp
src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj: src/GameObject/CMakeFiles/SeedButton.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj"
	cd /d E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj -MF CMakeFiles\SeedButton.dir\SeedButton.cpp.obj.d -o CMakeFiles\SeedButton.dir\SeedButton.cpp.obj -c E:\RICHARD\CS100\CS100-HW\hw8\attachments\src\GameObject\SeedButton.cpp

src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SeedButton.dir/SeedButton.cpp.i"
	cd /d E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\RICHARD\CS100\CS100-HW\hw8\attachments\src\GameObject\SeedButton.cpp > CMakeFiles\SeedButton.dir\SeedButton.cpp.i

src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SeedButton.dir/SeedButton.cpp.s"
	cd /d E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject && D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\RICHARD\CS100\CS100-HW\hw8\attachments\src\GameObject\SeedButton.cpp -o CMakeFiles\SeedButton.dir\SeedButton.cpp.s

# Object files for target SeedButton
SeedButton_OBJECTS = \
"CMakeFiles/SeedButton.dir/SeedButton.cpp.obj"

# External object files for target SeedButton
SeedButton_EXTERNAL_OBJECTS =

lib/libSeedButton.a: src/GameObject/CMakeFiles/SeedButton.dir/SeedButton.cpp.obj
lib/libSeedButton.a: src/GameObject/CMakeFiles/SeedButton.dir/build.make
lib/libSeedButton.a: src/GameObject/CMakeFiles/SeedButton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ..\..\lib\libSeedButton.a"
	cd /d E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject && $(CMAKE_COMMAND) -P CMakeFiles\SeedButton.dir\cmake_clean_target.cmake
	cd /d E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SeedButton.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GameObject/CMakeFiles/SeedButton.dir/build: lib/libSeedButton.a
.PHONY : src/GameObject/CMakeFiles/SeedButton.dir/build

src/GameObject/CMakeFiles/SeedButton.dir/clean:
	cd /d E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject && $(CMAKE_COMMAND) -P CMakeFiles\SeedButton.dir\cmake_clean.cmake
.PHONY : src/GameObject/CMakeFiles/SeedButton.dir/clean

src/GameObject/CMakeFiles/SeedButton.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\RICHARD\CS100\CS100-HW\hw8\attachments E:\RICHARD\CS100\CS100-HW\hw8\attachments\src\GameObject E:\RICHARD\CS100\CS100-HW\hw8\attachments\build E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject E:\RICHARD\CS100\CS100-HW\hw8\attachments\build\src\GameObject\CMakeFiles\SeedButton.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/GameObject/CMakeFiles/SeedButton.dir/depend

