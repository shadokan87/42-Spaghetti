# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/nfs/homes/motoure/42-Spaghetti

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/nfs/homes/motoure/42-Spaghetti/build

# Include any dependencies generated for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/depend.make

# Include the progress variables for this target.
include _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/flags.make

_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.o: _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/flags.make
_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.o: _deps/ftxui-src/examples/dom/color_info_palette256.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/nfs/homes/motoure/42-Spaghetti/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.o"
	cd /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.o -c /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-src/examples/dom/color_info_palette256.cpp

_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.i"
	cd /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-src/examples/dom/color_info_palette256.cpp > CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.i

_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.s"
	cd /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-src/examples/dom/color_info_palette256.cpp -o CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.s

# Object files for target color_info_palette256
color_info_palette256_OBJECTS = \
"CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.o"

# External object files for target color_info_palette256
color_info_palette256_EXTERNAL_OBJECTS =

_deps/ftxui-build/examples/dom/color_info_palette256: _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/color_info_palette256.cpp.o
_deps/ftxui-build/examples/dom/color_info_palette256: _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/build.make
_deps/ftxui-build/examples/dom/color_info_palette256: _deps/ftxui-build/ftxui-dom.a
_deps/ftxui-build/examples/dom/color_info_palette256: _deps/ftxui-build/ftxui-screen.a
_deps/ftxui-build/examples/dom/color_info_palette256: _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/nfs/homes/motoure/42-Spaghetti/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable color_info_palette256"
	cd /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/color_info_palette256.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/build: _deps/ftxui-build/examples/dom/color_info_palette256

.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/build

_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/clean:
	cd /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom && $(CMAKE_COMMAND) -P CMakeFiles/color_info_palette256.dir/cmake_clean.cmake
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/clean

_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/depend:
	cd /mnt/nfs/homes/motoure/42-Spaghetti/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/nfs/homes/motoure/42-Spaghetti /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-src/examples/dom /mnt/nfs/homes/motoure/42-Spaghetti/build /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom /mnt/nfs/homes/motoure/42-Spaghetti/build/_deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/ftxui-build/examples/dom/CMakeFiles/color_info_palette256.dir/depend

