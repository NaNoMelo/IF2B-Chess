# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yannt\Desktop\IF2A\IF2B-Chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IF2B_Chess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IF2B_Chess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IF2B_Chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IF2B_Chess.dir/flags.make

CMakeFiles/IF2B_Chess.dir/main.c.obj: CMakeFiles/IF2B_Chess.dir/flags.make
CMakeFiles/IF2B_Chess.dir/main.c.obj: ../main.c
CMakeFiles/IF2B_Chess.dir/main.c.obj: CMakeFiles/IF2B_Chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/IF2B_Chess.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/IF2B_Chess.dir/main.c.obj -MF CMakeFiles\IF2B_Chess.dir\main.c.obj.d -o CMakeFiles\IF2B_Chess.dir\main.c.obj -c C:\Users\yannt\Desktop\IF2A\IF2B-Chess\main.c

CMakeFiles/IF2B_Chess.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IF2B_Chess.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yannt\Desktop\IF2A\IF2B-Chess\main.c > CMakeFiles\IF2B_Chess.dir\main.c.i

CMakeFiles/IF2B_Chess.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IF2B_Chess.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yannt\Desktop\IF2A\IF2B-Chess\main.c -o CMakeFiles\IF2B_Chess.dir\main.c.s

CMakeFiles/IF2B_Chess.dir/saisie.c.obj: CMakeFiles/IF2B_Chess.dir/flags.make
CMakeFiles/IF2B_Chess.dir/saisie.c.obj: ../saisie.c
CMakeFiles/IF2B_Chess.dir/saisie.c.obj: CMakeFiles/IF2B_Chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/IF2B_Chess.dir/saisie.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/IF2B_Chess.dir/saisie.c.obj -MF CMakeFiles\IF2B_Chess.dir\saisie.c.obj.d -o CMakeFiles\IF2B_Chess.dir\saisie.c.obj -c C:\Users\yannt\Desktop\IF2A\IF2B-Chess\saisie.c

CMakeFiles/IF2B_Chess.dir/saisie.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IF2B_Chess.dir/saisie.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yannt\Desktop\IF2A\IF2B-Chess\saisie.c > CMakeFiles\IF2B_Chess.dir\saisie.c.i

CMakeFiles/IF2B_Chess.dir/saisie.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IF2B_Chess.dir/saisie.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yannt\Desktop\IF2A\IF2B-Chess\saisie.c -o CMakeFiles\IF2B_Chess.dir\saisie.c.s

CMakeFiles/IF2B_Chess.dir/board.c.obj: CMakeFiles/IF2B_Chess.dir/flags.make
CMakeFiles/IF2B_Chess.dir/board.c.obj: ../board.c
CMakeFiles/IF2B_Chess.dir/board.c.obj: CMakeFiles/IF2B_Chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/IF2B_Chess.dir/board.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/IF2B_Chess.dir/board.c.obj -MF CMakeFiles\IF2B_Chess.dir\board.c.obj.d -o CMakeFiles\IF2B_Chess.dir\board.c.obj -c C:\Users\yannt\Desktop\IF2A\IF2B-Chess\board.c

CMakeFiles/IF2B_Chess.dir/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IF2B_Chess.dir/board.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yannt\Desktop\IF2A\IF2B-Chess\board.c > CMakeFiles\IF2B_Chess.dir\board.c.i

CMakeFiles/IF2B_Chess.dir/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IF2B_Chess.dir/board.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yannt\Desktop\IF2A\IF2B-Chess\board.c -o CMakeFiles\IF2B_Chess.dir\board.c.s

CMakeFiles/IF2B_Chess.dir/verif.c.obj: CMakeFiles/IF2B_Chess.dir/flags.make
CMakeFiles/IF2B_Chess.dir/verif.c.obj: ../verif.c
CMakeFiles/IF2B_Chess.dir/verif.c.obj: CMakeFiles/IF2B_Chess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/IF2B_Chess.dir/verif.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/IF2B_Chess.dir/verif.c.obj -MF CMakeFiles\IF2B_Chess.dir\verif.c.obj.d -o CMakeFiles\IF2B_Chess.dir\verif.c.obj -c C:\Users\yannt\Desktop\IF2A\IF2B-Chess\verif.c

CMakeFiles/IF2B_Chess.dir/verif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/IF2B_Chess.dir/verif.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\yannt\Desktop\IF2A\IF2B-Chess\verif.c > CMakeFiles\IF2B_Chess.dir\verif.c.i

CMakeFiles/IF2B_Chess.dir/verif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/IF2B_Chess.dir/verif.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\yannt\Desktop\IF2A\IF2B-Chess\verif.c -o CMakeFiles\IF2B_Chess.dir\verif.c.s

# Object files for target IF2B_Chess
IF2B_Chess_OBJECTS = \
"CMakeFiles/IF2B_Chess.dir/main.c.obj" \
"CMakeFiles/IF2B_Chess.dir/saisie.c.obj" \
"CMakeFiles/IF2B_Chess.dir/board.c.obj" \
"CMakeFiles/IF2B_Chess.dir/verif.c.obj"

# External object files for target IF2B_Chess
IF2B_Chess_EXTERNAL_OBJECTS =

IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/main.c.obj
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/saisie.c.obj
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/board.c.obj
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/verif.c.obj
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/build.make
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/linklibs.rsp
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/objects1.rsp
IF2B_Chess.exe: CMakeFiles/IF2B_Chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable IF2B_Chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IF2B_Chess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IF2B_Chess.dir/build: IF2B_Chess.exe
.PHONY : CMakeFiles/IF2B_Chess.dir/build

CMakeFiles/IF2B_Chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IF2B_Chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IF2B_Chess.dir/clean

CMakeFiles/IF2B_Chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yannt\Desktop\IF2A\IF2B-Chess C:\Users\yannt\Desktop\IF2A\IF2B-Chess C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug C:\Users\yannt\Desktop\IF2A\IF2B-Chess\cmake-build-debug\CMakeFiles\IF2B_Chess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IF2B_Chess.dir/depend

