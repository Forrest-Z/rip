# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/sebastian/Programming/rip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastian/Programming/rip

# Include any dependencies generated for this target.
include external/stp/CMakeFiles/stp.dir/depend.make

# Include the progress variables for this target.
include external/stp/CMakeFiles/stp.dir/progress.make

# Include the compile flags for this target's objects.
include external/stp/CMakeFiles/stp.dir/flags.make

external/stp/CMakeFiles/stp.dir/src/stp3.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/stp3.cc.o: external/stp/src/stp3.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object external/stp/CMakeFiles/stp.dir/src/stp3.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/stp3.cc.o -c /home/sebastian/Programming/rip/external/stp/src/stp3.cc

external/stp/CMakeFiles/stp.dir/src/stp3.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/stp3.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/stp3.cc > CMakeFiles/stp.dir/src/stp3.cc.i

external/stp/CMakeFiles/stp.dir/src/stp3.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/stp3.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/stp3.cc -o CMakeFiles/stp.dir/src/stp3.cc.s

external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/stp3.cc.o


external/stp/CMakeFiles/stp.dir/src/stp7.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/stp7.cc.o: external/stp/src/stp7.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object external/stp/CMakeFiles/stp.dir/src/stp7.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/stp7.cc.o -c /home/sebastian/Programming/rip/external/stp/src/stp7.cc

external/stp/CMakeFiles/stp.dir/src/stp7.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/stp7.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/stp7.cc > CMakeFiles/stp.dir/src/stp7.cc.i

external/stp/CMakeFiles/stp.dir/src/stp7.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/stp7.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/stp7.cc -o CMakeFiles/stp.dir/src/stp7.cc.s

external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/stp7.cc.o


external/stp/CMakeFiles/stp.dir/src/STP.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/STP.cc.o: external/stp/src/STP.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object external/stp/CMakeFiles/stp.dir/src/STP.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/STP.cc.o -c /home/sebastian/Programming/rip/external/stp/src/STP.cc

external/stp/CMakeFiles/stp.dir/src/STP.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/STP.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/STP.cc > CMakeFiles/stp.dir/src/STP.cc.i

external/stp/CMakeFiles/stp.dir/src/STP.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/STP.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/STP.cc -o CMakeFiles/stp.dir/src/STP.cc.s

external/stp/CMakeFiles/stp.dir/src/STP.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/STP.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/STP.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/STP.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/STP.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/STP.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/STP.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/STP.cc.o


external/stp/CMakeFiles/stp.dir/src/stp1.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/stp1.cc.o: external/stp/src/stp1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object external/stp/CMakeFiles/stp.dir/src/stp1.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/stp1.cc.o -c /home/sebastian/Programming/rip/external/stp/src/stp1.cc

external/stp/CMakeFiles/stp.dir/src/stp1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/stp1.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/stp1.cc > CMakeFiles/stp.dir/src/stp1.cc.i

external/stp/CMakeFiles/stp.dir/src/stp1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/stp1.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/stp1.cc -o CMakeFiles/stp.dir/src/stp1.cc.s

external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/stp1.cc.o


external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o: external/stp/src/polynomial.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/polynomial.cc.o -c /home/sebastian/Programming/rip/external/stp/src/polynomial.cc

external/stp/CMakeFiles/stp.dir/src/polynomial.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/polynomial.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/polynomial.cc > CMakeFiles/stp.dir/src/polynomial.cc.i

external/stp/CMakeFiles/stp.dir/src/polynomial.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/polynomial.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/polynomial.cc -o CMakeFiles/stp.dir/src/polynomial.cc.s

external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o


external/stp/CMakeFiles/stp.dir/src/tools.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/tools.cc.o: external/stp/src/tools.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object external/stp/CMakeFiles/stp.dir/src/tools.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/tools.cc.o -c /home/sebastian/Programming/rip/external/stp/src/tools.cc

external/stp/CMakeFiles/stp.dir/src/tools.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/tools.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/tools.cc > CMakeFiles/stp.dir/src/tools.cc.i

external/stp/CMakeFiles/stp.dir/src/tools.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/tools.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/tools.cc -o CMakeFiles/stp.dir/src/tools.cc.s

external/stp/CMakeFiles/stp.dir/src/tools.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/tools.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/tools.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/tools.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/tools.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/tools.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/tools.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/tools.cc.o


external/stp/CMakeFiles/stp.dir/src/complex.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/complex.cc.o: external/stp/src/complex.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object external/stp/CMakeFiles/stp.dir/src/complex.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/complex.cc.o -c /home/sebastian/Programming/rip/external/stp/src/complex.cc

external/stp/CMakeFiles/stp.dir/src/complex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/complex.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/complex.cc > CMakeFiles/stp.dir/src/complex.cc.i

external/stp/CMakeFiles/stp.dir/src/complex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/complex.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/complex.cc -o CMakeFiles/stp.dir/src/complex.cc.s

external/stp/CMakeFiles/stp.dir/src/complex.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/complex.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/complex.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/complex.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/complex.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/complex.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/complex.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/complex.cc.o


external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o: external/stp/src/multi_stp.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/multi_stp.cc.o -c /home/sebastian/Programming/rip/external/stp/src/multi_stp.cc

external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/multi_stp.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/multi_stp.cc > CMakeFiles/stp.dir/src/multi_stp.cc.i

external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/multi_stp.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/multi_stp.cc -o CMakeFiles/stp.dir/src/multi_stp.cc.s

external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o


external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o: external/stp/CMakeFiles/stp.dir/flags.make
external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o: external/stp/src/stp7_formulas.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stp.dir/src/stp7_formulas.cc.o -c /home/sebastian/Programming/rip/external/stp/src/stp7_formulas.cc

external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stp.dir/src/stp7_formulas.cc.i"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Programming/rip/external/stp/src/stp7_formulas.cc > CMakeFiles/stp.dir/src/stp7_formulas.cc.i

external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stp.dir/src/stp7_formulas.cc.s"
	cd /home/sebastian/Programming/rip/external/stp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Programming/rip/external/stp/src/stp7_formulas.cc -o CMakeFiles/stp.dir/src/stp7_formulas.cc.s

external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.requires:

.PHONY : external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.requires

external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.provides: external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.requires
	$(MAKE) -f external/stp/CMakeFiles/stp.dir/build.make external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.provides.build
.PHONY : external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.provides

external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.provides.build: external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o


# Object files for target stp
stp_OBJECTS = \
"CMakeFiles/stp.dir/src/stp3.cc.o" \
"CMakeFiles/stp.dir/src/stp7.cc.o" \
"CMakeFiles/stp.dir/src/STP.cc.o" \
"CMakeFiles/stp.dir/src/stp1.cc.o" \
"CMakeFiles/stp.dir/src/polynomial.cc.o" \
"CMakeFiles/stp.dir/src/tools.cc.o" \
"CMakeFiles/stp.dir/src/complex.cc.o" \
"CMakeFiles/stp.dir/src/multi_stp.cc.o" \
"CMakeFiles/stp.dir/src/stp7_formulas.cc.o"

# External object files for target stp
stp_EXTERNAL_OBJECTS =

external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/stp3.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/stp7.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/STP.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/stp1.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/tools.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/complex.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/build.make
external/stp/libstp.a: external/stp/CMakeFiles/stp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sebastian/Programming/rip/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libstp.a"
	cd /home/sebastian/Programming/rip/external/stp && $(CMAKE_COMMAND) -P CMakeFiles/stp.dir/cmake_clean_target.cmake
	cd /home/sebastian/Programming/rip/external/stp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/stp/CMakeFiles/stp.dir/build: external/stp/libstp.a

.PHONY : external/stp/CMakeFiles/stp.dir/build

external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/stp3.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/stp7.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/STP.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/stp1.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/polynomial.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/tools.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/complex.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/multi_stp.cc.o.requires
external/stp/CMakeFiles/stp.dir/requires: external/stp/CMakeFiles/stp.dir/src/stp7_formulas.cc.o.requires

.PHONY : external/stp/CMakeFiles/stp.dir/requires

external/stp/CMakeFiles/stp.dir/clean:
	cd /home/sebastian/Programming/rip/external/stp && $(CMAKE_COMMAND) -P CMakeFiles/stp.dir/cmake_clean.cmake
.PHONY : external/stp/CMakeFiles/stp.dir/clean

external/stp/CMakeFiles/stp.dir/depend:
	cd /home/sebastian/Programming/rip && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastian/Programming/rip /home/sebastian/Programming/rip/external/stp /home/sebastian/Programming/rip /home/sebastian/Programming/rip/external/stp /home/sebastian/Programming/rip/external/stp/CMakeFiles/stp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : external/stp/CMakeFiles/stp.dir/depend
