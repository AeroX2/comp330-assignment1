# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/james/documents/git/comp330-assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/james/documents/git/comp330-assignment1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/james/documents/git/comp330-assignment1/CMakeFiles /home/james/documents/git/comp330-assignment1/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/james/documents/git/comp330-assignment1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named comp330_assignment1

# Build rule for target.
comp330_assignment1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 comp330_assignment1
.PHONY : comp330_assignment1

# fast build rule for target.
comp330_assignment1/fast:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/build
.PHONY : comp330_assignment1/fast

src/entities/entity.o: src/entities/entity.cpp.o

.PHONY : src/entities/entity.o

# target to build an object file
src/entities/entity.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/entity.cpp.o
.PHONY : src/entities/entity.cpp.o

src/entities/entity.i: src/entities/entity.cpp.i

.PHONY : src/entities/entity.i

# target to preprocess a source file
src/entities/entity.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/entity.cpp.i
.PHONY : src/entities/entity.cpp.i

src/entities/entity.s: src/entities/entity.cpp.s

.PHONY : src/entities/entity.s

# target to generate assembly for a file
src/entities/entity.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/entity.cpp.s
.PHONY : src/entities/entity.cpp.s

src/entities/fire.o: src/entities/fire.cpp.o

.PHONY : src/entities/fire.o

# target to build an object file
src/entities/fire.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/fire.cpp.o
.PHONY : src/entities/fire.cpp.o

src/entities/fire.i: src/entities/fire.cpp.i

.PHONY : src/entities/fire.i

# target to preprocess a source file
src/entities/fire.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/fire.cpp.i
.PHONY : src/entities/fire.cpp.i

src/entities/fire.s: src/entities/fire.cpp.s

.PHONY : src/entities/fire.s

# target to generate assembly for a file
src/entities/fire.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/fire.cpp.s
.PHONY : src/entities/fire.cpp.s

src/entities/helicopter.o: src/entities/helicopter.cpp.o

.PHONY : src/entities/helicopter.o

# target to build an object file
src/entities/helicopter.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/helicopter.cpp.o
.PHONY : src/entities/helicopter.cpp.o

src/entities/helicopter.i: src/entities/helicopter.cpp.i

.PHONY : src/entities/helicopter.i

# target to preprocess a source file
src/entities/helicopter.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/helicopter.cpp.i
.PHONY : src/entities/helicopter.cpp.i

src/entities/helicopter.s: src/entities/helicopter.cpp.s

.PHONY : src/entities/helicopter.s

# target to generate assembly for a file
src/entities/helicopter.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/helicopter.cpp.s
.PHONY : src/entities/helicopter.cpp.s

src/entities/house.o: src/entities/house.cpp.o

.PHONY : src/entities/house.o

# target to build an object file
src/entities/house.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/house.cpp.o
.PHONY : src/entities/house.cpp.o

src/entities/house.i: src/entities/house.cpp.i

.PHONY : src/entities/house.i

# target to preprocess a source file
src/entities/house.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/house.cpp.i
.PHONY : src/entities/house.cpp.i

src/entities/house.s: src/entities/house.cpp.s

.PHONY : src/entities/house.s

# target to generate assembly for a file
src/entities/house.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/house.cpp.s
.PHONY : src/entities/house.cpp.s

src/entities/lake.o: src/entities/lake.cpp.o

.PHONY : src/entities/lake.o

# target to build an object file
src/entities/lake.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/lake.cpp.o
.PHONY : src/entities/lake.cpp.o

src/entities/lake.i: src/entities/lake.cpp.i

.PHONY : src/entities/lake.i

# target to preprocess a source file
src/entities/lake.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/lake.cpp.i
.PHONY : src/entities/lake.cpp.i

src/entities/lake.s: src/entities/lake.cpp.s

.PHONY : src/entities/lake.s

# target to generate assembly for a file
src/entities/lake.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/lake.cpp.s
.PHONY : src/entities/lake.cpp.s

src/entities/splash.o: src/entities/splash.cpp.o

.PHONY : src/entities/splash.o

# target to build an object file
src/entities/splash.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/splash.cpp.o
.PHONY : src/entities/splash.cpp.o

src/entities/splash.i: src/entities/splash.cpp.i

.PHONY : src/entities/splash.i

# target to preprocess a source file
src/entities/splash.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/splash.cpp.i
.PHONY : src/entities/splash.cpp.i

src/entities/splash.s: src/entities/splash.cpp.s

.PHONY : src/entities/splash.s

# target to generate assembly for a file
src/entities/splash.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/splash.cpp.s
.PHONY : src/entities/splash.cpp.s

src/entities/vector.o: src/entities/vector.cpp.o

.PHONY : src/entities/vector.o

# target to build an object file
src/entities/vector.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/vector.cpp.o
.PHONY : src/entities/vector.cpp.o

src/entities/vector.i: src/entities/vector.cpp.i

.PHONY : src/entities/vector.i

# target to preprocess a source file
src/entities/vector.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/vector.cpp.i
.PHONY : src/entities/vector.cpp.i

src/entities/vector.s: src/entities/vector.cpp.s

.PHONY : src/entities/vector.s

# target to generate assembly for a file
src/entities/vector.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/entities/vector.cpp.s
.PHONY : src/entities/vector.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/utils.o: src/utils.cpp.o

.PHONY : src/utils.o

# target to build an object file
src/utils.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/utils.cpp.o
.PHONY : src/utils.cpp.o

src/utils.i: src/utils.cpp.i

.PHONY : src/utils.i

# target to preprocess a source file
src/utils.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/utils.cpp.i
.PHONY : src/utils.cpp.i

src/utils.s: src/utils.cpp.s

.PHONY : src/utils.s

# target to generate assembly for a file
src/utils.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/utils.cpp.s
.PHONY : src/utils.cpp.s

src/world.o: src/world.cpp.o

.PHONY : src/world.o

# target to build an object file
src/world.cpp.o:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/world.cpp.o
.PHONY : src/world.cpp.o

src/world.i: src/world.cpp.i

.PHONY : src/world.i

# target to preprocess a source file
src/world.cpp.i:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/world.cpp.i
.PHONY : src/world.cpp.i

src/world.s: src/world.cpp.s

.PHONY : src/world.s

# target to generate assembly for a file
src/world.cpp.s:
	$(MAKE) -f CMakeFiles/comp330_assignment1.dir/build.make CMakeFiles/comp330_assignment1.dir/src/world.cpp.s
.PHONY : src/world.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... comp330_assignment1"
	@echo "... edit_cache"
	@echo "... src/entities/entity.o"
	@echo "... src/entities/entity.i"
	@echo "... src/entities/entity.s"
	@echo "... src/entities/fire.o"
	@echo "... src/entities/fire.i"
	@echo "... src/entities/fire.s"
	@echo "... src/entities/helicopter.o"
	@echo "... src/entities/helicopter.i"
	@echo "... src/entities/helicopter.s"
	@echo "... src/entities/house.o"
	@echo "... src/entities/house.i"
	@echo "... src/entities/house.s"
	@echo "... src/entities/lake.o"
	@echo "... src/entities/lake.i"
	@echo "... src/entities/lake.s"
	@echo "... src/entities/splash.o"
	@echo "... src/entities/splash.i"
	@echo "... src/entities/splash.s"
	@echo "... src/entities/vector.o"
	@echo "... src/entities/vector.i"
	@echo "... src/entities/vector.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/utils.o"
	@echo "... src/utils.i"
	@echo "... src/utils.s"
	@echo "... src/world.o"
	@echo "... src/world.i"
	@echo "... src/world.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

