# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /C/msys64/mingw64/bin/cmake.exe

# The command to remove a file.
RM = /C/msys64/mingw64/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /C/Users/local_admin/Desktop/TSI/Projects/Theatre

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /C/Users/local_admin/Desktop/TSI/Projects/Theatre/build

# Include any dependencies generated for this target.
include CMakeFiles/Theatre.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Theatre.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Theatre.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Theatre.dir/flags.make

CMakeFiles/Theatre.dir/src/main.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/Theatre.dir/src/main.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Theatre.dir/src/main.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/main.cpp.obj -MF CMakeFiles/Theatre.dir/src/main.cpp.obj.d -o CMakeFiles/Theatre.dir/src/main.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/main.cpp

CMakeFiles/Theatre.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/main.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/main.cpp > CMakeFiles/Theatre.dir/src/main.cpp.i

CMakeFiles/Theatre.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/main.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/main.cpp -o CMakeFiles/Theatre.dir/src/main.cpp.s

CMakeFiles/Theatre.dir/src/actor.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/actor.cpp.obj: ../src/actor.cpp
CMakeFiles/Theatre.dir/src/actor.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Theatre.dir/src/actor.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/actor.cpp.obj -MF CMakeFiles/Theatre.dir/src/actor.cpp.obj.d -o CMakeFiles/Theatre.dir/src/actor.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/actor.cpp

CMakeFiles/Theatre.dir/src/actor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/actor.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/actor.cpp > CMakeFiles/Theatre.dir/src/actor.cpp.i

CMakeFiles/Theatre.dir/src/actor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/actor.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/actor.cpp -o CMakeFiles/Theatre.dir/src/actor.cpp.s

CMakeFiles/Theatre.dir/src/employee.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/employee.cpp.obj: ../src/employee.cpp
CMakeFiles/Theatre.dir/src/employee.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Theatre.dir/src/employee.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/employee.cpp.obj -MF CMakeFiles/Theatre.dir/src/employee.cpp.obj.d -o CMakeFiles/Theatre.dir/src/employee.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/employee.cpp

CMakeFiles/Theatre.dir/src/employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/employee.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/employee.cpp > CMakeFiles/Theatre.dir/src/employee.cpp.i

CMakeFiles/Theatre.dir/src/employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/employee.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/employee.cpp -o CMakeFiles/Theatre.dir/src/employee.cpp.s

CMakeFiles/Theatre.dir/src/hall.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/hall.cpp.obj: ../src/hall.cpp
CMakeFiles/Theatre.dir/src/hall.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Theatre.dir/src/hall.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/hall.cpp.obj -MF CMakeFiles/Theatre.dir/src/hall.cpp.obj.d -o CMakeFiles/Theatre.dir/src/hall.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/hall.cpp

CMakeFiles/Theatre.dir/src/hall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/hall.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/hall.cpp > CMakeFiles/Theatre.dir/src/hall.cpp.i

CMakeFiles/Theatre.dir/src/hall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/hall.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/hall.cpp -o CMakeFiles/Theatre.dir/src/hall.cpp.s

CMakeFiles/Theatre.dir/src/musical.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/musical.cpp.obj: ../src/musical.cpp
CMakeFiles/Theatre.dir/src/musical.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Theatre.dir/src/musical.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/musical.cpp.obj -MF CMakeFiles/Theatre.dir/src/musical.cpp.obj.d -o CMakeFiles/Theatre.dir/src/musical.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/musical.cpp

CMakeFiles/Theatre.dir/src/musical.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/musical.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/musical.cpp > CMakeFiles/Theatre.dir/src/musical.cpp.i

CMakeFiles/Theatre.dir/src/musical.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/musical.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/musical.cpp -o CMakeFiles/Theatre.dir/src/musical.cpp.s

CMakeFiles/Theatre.dir/src/musician.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/musician.cpp.obj: ../src/musician.cpp
CMakeFiles/Theatre.dir/src/musician.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Theatre.dir/src/musician.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/musician.cpp.obj -MF CMakeFiles/Theatre.dir/src/musician.cpp.obj.d -o CMakeFiles/Theatre.dir/src/musician.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/musician.cpp

CMakeFiles/Theatre.dir/src/musician.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/musician.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/musician.cpp > CMakeFiles/Theatre.dir/src/musician.cpp.i

CMakeFiles/Theatre.dir/src/musician.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/musician.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/musician.cpp -o CMakeFiles/Theatre.dir/src/musician.cpp.s

CMakeFiles/Theatre.dir/src/performance.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/performance.cpp.obj: ../src/performance.cpp
CMakeFiles/Theatre.dir/src/performance.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Theatre.dir/src/performance.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/performance.cpp.obj -MF CMakeFiles/Theatre.dir/src/performance.cpp.obj.d -o CMakeFiles/Theatre.dir/src/performance.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/performance.cpp

CMakeFiles/Theatre.dir/src/performance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/performance.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/performance.cpp > CMakeFiles/Theatre.dir/src/performance.cpp.i

CMakeFiles/Theatre.dir/src/performance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/performance.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/performance.cpp -o CMakeFiles/Theatre.dir/src/performance.cpp.s

CMakeFiles/Theatre.dir/src/performer.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/performer.cpp.obj: ../src/performer.cpp
CMakeFiles/Theatre.dir/src/performer.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Theatre.dir/src/performer.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/performer.cpp.obj -MF CMakeFiles/Theatre.dir/src/performer.cpp.obj.d -o CMakeFiles/Theatre.dir/src/performer.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/performer.cpp

CMakeFiles/Theatre.dir/src/performer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/performer.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/performer.cpp > CMakeFiles/Theatre.dir/src/performer.cpp.i

CMakeFiles/Theatre.dir/src/performer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/performer.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/performer.cpp -o CMakeFiles/Theatre.dir/src/performer.cpp.s

CMakeFiles/Theatre.dir/src/play.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/play.cpp.obj: ../src/play.cpp
CMakeFiles/Theatre.dir/src/play.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Theatre.dir/src/play.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/play.cpp.obj -MF CMakeFiles/Theatre.dir/src/play.cpp.obj.d -o CMakeFiles/Theatre.dir/src/play.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/play.cpp

CMakeFiles/Theatre.dir/src/play.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/play.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/play.cpp > CMakeFiles/Theatre.dir/src/play.cpp.i

CMakeFiles/Theatre.dir/src/play.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/play.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/play.cpp -o CMakeFiles/Theatre.dir/src/play.cpp.s

CMakeFiles/Theatre.dir/src/singer.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/singer.cpp.obj: ../src/singer.cpp
CMakeFiles/Theatre.dir/src/singer.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Theatre.dir/src/singer.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/singer.cpp.obj -MF CMakeFiles/Theatre.dir/src/singer.cpp.obj.d -o CMakeFiles/Theatre.dir/src/singer.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/singer.cpp

CMakeFiles/Theatre.dir/src/singer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/singer.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/singer.cpp > CMakeFiles/Theatre.dir/src/singer.cpp.i

CMakeFiles/Theatre.dir/src/singer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/singer.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/singer.cpp -o CMakeFiles/Theatre.dir/src/singer.cpp.s

CMakeFiles/Theatre.dir/src/sysManager.cpp.obj: CMakeFiles/Theatre.dir/flags.make
CMakeFiles/Theatre.dir/src/sysManager.cpp.obj: ../src/sysManager.cpp
CMakeFiles/Theatre.dir/src/sysManager.cpp.obj: CMakeFiles/Theatre.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Theatre.dir/src/sysManager.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Theatre.dir/src/sysManager.cpp.obj -MF CMakeFiles/Theatre.dir/src/sysManager.cpp.obj.d -o CMakeFiles/Theatre.dir/src/sysManager.cpp.obj -c /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/sysManager.cpp

CMakeFiles/Theatre.dir/src/sysManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Theatre.dir/src/sysManager.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/sysManager.cpp > CMakeFiles/Theatre.dir/src/sysManager.cpp.i

CMakeFiles/Theatre.dir/src/sysManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Theatre.dir/src/sysManager.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/local_admin/Desktop/TSI/Projects/Theatre/src/sysManager.cpp -o CMakeFiles/Theatre.dir/src/sysManager.cpp.s

# Object files for target Theatre
Theatre_OBJECTS = \
"CMakeFiles/Theatre.dir/src/main.cpp.obj" \
"CMakeFiles/Theatre.dir/src/actor.cpp.obj" \
"CMakeFiles/Theatre.dir/src/employee.cpp.obj" \
"CMakeFiles/Theatre.dir/src/hall.cpp.obj" \
"CMakeFiles/Theatre.dir/src/musical.cpp.obj" \
"CMakeFiles/Theatre.dir/src/musician.cpp.obj" \
"CMakeFiles/Theatre.dir/src/performance.cpp.obj" \
"CMakeFiles/Theatre.dir/src/performer.cpp.obj" \
"CMakeFiles/Theatre.dir/src/play.cpp.obj" \
"CMakeFiles/Theatre.dir/src/singer.cpp.obj" \
"CMakeFiles/Theatre.dir/src/sysManager.cpp.obj"

# External object files for target Theatre
Theatre_EXTERNAL_OBJECTS =

Theatre.exe: CMakeFiles/Theatre.dir/src/main.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/actor.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/employee.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/hall.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/musical.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/musician.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/performance.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/performer.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/play.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/singer.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/src/sysManager.cpp.obj
Theatre.exe: CMakeFiles/Theatre.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Theatre.exe"
	/C/msys64/mingw64/bin/cmake.exe -E rm -f CMakeFiles/Theatre.dir/objects.a
	/C/msys64/mingw64/bin/ar.exe qc CMakeFiles/Theatre.dir/objects.a $(Theatre_OBJECTS) $(Theatre_EXTERNAL_OBJECTS)
	/C/msys64/mingw64/bin/g++.exe -Wl,--whole-archive CMakeFiles/Theatre.dir/objects.a -Wl,--no-whole-archive -o Theatre.exe -Wl,--out-implib,libTheatre.dll.a -Wl,--major-image-version,0,--minor-image-version,0  -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -luuid -lcomdlg32 -ladvapi32 

# Rule to build all files generated by this target.
CMakeFiles/Theatre.dir/build: Theatre.exe
.PHONY : CMakeFiles/Theatre.dir/build

CMakeFiles/Theatre.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Theatre.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Theatre.dir/clean

CMakeFiles/Theatre.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/local_admin/Desktop/TSI/Projects/Theatre /C/Users/local_admin/Desktop/TSI/Projects/Theatre /C/Users/local_admin/Desktop/TSI/Projects/Theatre/build /C/Users/local_admin/Desktop/TSI/Projects/Theatre/build /C/Users/local_admin/Desktop/TSI/Projects/Theatre/build/CMakeFiles/Theatre.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Theatre.dir/depend

