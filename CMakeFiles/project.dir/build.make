# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/Files/c/university/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/Files/c/university/project

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/cmd/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/cmd/main.cpp.o: cmd/main.cpp
CMakeFiles/project.dir/cmd/main.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/Files/c/university/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/cmd/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/cmd/main.cpp.o -MF CMakeFiles/project.dir/cmd/main.cpp.o.d -o CMakeFiles/project.dir/cmd/main.cpp.o -c /Volumes/Files/c/university/project/cmd/main.cpp

CMakeFiles/project.dir/cmd/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/cmd/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/Files/c/university/project/cmd/main.cpp > CMakeFiles/project.dir/cmd/main.cpp.i

CMakeFiles/project.dir/cmd/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/cmd/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/Files/c/university/project/cmd/main.cpp -o CMakeFiles/project.dir/cmd/main.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/cmd/main.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

build/project: CMakeFiles/project.dir/cmd/main.cpp.o
build/project: CMakeFiles/project.dir/build.make
build/project: lib/darwin/gtest/libgtest_main.a
build/project: lib/darwin/gtest/libgtest.a
build/project: lib/darwin/gtkmm/libgtkmm-3.0.dylib
build/project: lib/darwin/glibmm/libglibmm_generate_extra_defs-2.4.dylib
build/project: lib/darwin/glibmm/libglibmm-2.4.dylib
build/project: lib/darwin/giomm/libgiomm-2.68.dylib
build/project: lib/darwin/glib/libglib-2.0.dylib
build/project: lib/darwin/sigc++/libsigc-2.0.dylib
build/project: lib/darwin/gdkmm/libgdk-3.0.dylib
build/project: lib/darwin/pangomm/libpangomm-1.4.dylib
build/project: lib/darwin/gtk/libgdk-3.0.dylib
build/project: lib/darwin/gdk/libgtk-3.0.dylib
build/project: lib/darwin/pango/libpango-1.0.a
build/project: lib/darwin/harfbuzz/libharfbuzz.a
build/project: lib/darwin/cairo/cairo.a
build/project: lib/darwin/cairo/cairo-fdr.a
build/project: lib/darwin/cairo/cairo-sphinx.a
build/project: lib/darwin/cairo/libcairo-trace.a
build/project: lib/darwin/cairomm/libcairomm-1.0
build/project: lib/darwin/gdk-pixbuf/libgdk_pixbuf-2.0.dylib
build/project: lib/darwin/freetype2/libfreetype.a
build/project: lib/darwin/fontconfig/libfontconfig.a
build/project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/Files/c/university/project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable build/project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: build/project
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /Volumes/Files/c/university/project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/Files/c/university/project /Volumes/Files/c/university/project /Volumes/Files/c/university/project /Volumes/Files/c/university/project /Volumes/Files/c/university/project/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

