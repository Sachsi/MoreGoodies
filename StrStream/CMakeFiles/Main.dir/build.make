# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The CMake executable.
CMAKE_COMMAND = /data/data/ru.iiec.cxxdroid/files/bin/cmake

# The command to remove a file.
RM = /data/data/ru.iiec.cxxdroid/files/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /storage/emulated/0/CppProjects/MoreGoodies/StrStream

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /storage/emulated/0/CppProjects/MoreGoodies/StrStream

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/src/main.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Main.dir/src/main.cpp.o: CMakeFiles/Main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/storage/emulated/0/CppProjects/MoreGoodies/StrStream/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/src/main.cpp.o"
	/data/user/0/ru.iiec.cxxdroid/files/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Main.dir/src/main.cpp.o -MF CMakeFiles/Main.dir/src/main.cpp.o.d -o CMakeFiles/Main.dir/src/main.cpp.o -c /storage/emulated/0/CppProjects/MoreGoodies/StrStream/src/main.cpp

CMakeFiles/Main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/main.cpp.i"
	/data/user/0/ru.iiec.cxxdroid/files/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /storage/emulated/0/CppProjects/MoreGoodies/StrStream/src/main.cpp > CMakeFiles/Main.dir/src/main.cpp.i

CMakeFiles/Main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/main.cpp.s"
	/data/user/0/ru.iiec.cxxdroid/files/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /storage/emulated/0/CppProjects/MoreGoodies/StrStream/src/main.cpp -o CMakeFiles/Main.dir/src/main.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/src/main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main: CMakeFiles/Main.dir/src/main.cpp.o
Main: CMakeFiles/Main.dir/build.make
Main: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/storage/emulated/0/CppProjects/MoreGoodies/StrStream/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main
.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd /storage/emulated/0/CppProjects/MoreGoodies/StrStream && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /storage/emulated/0/CppProjects/MoreGoodies/StrStream /storage/emulated/0/CppProjects/MoreGoodies/StrStream /storage/emulated/0/CppProjects/MoreGoodies/StrStream /storage/emulated/0/CppProjects/MoreGoodies/StrStream /storage/emulated/0/CppProjects/MoreGoodies/StrStream/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend

