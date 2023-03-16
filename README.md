# note-box
A notepad-centric GUI file manager with cloud update and sync. Write your important notes and sync them with the cloud.

# Building on Linux
- Install a compiler toolchain like Clang/LLVM, CMake, SCons
- Download the dependencies in the dependencies folder from GitHub, and build using CMake
- Go through the CMake GUI and ensure you install the dev libraries for all the dependencies' dependencies. E.g for SFML install libudev-dev for libudev. The -dev suffix means it's a dev library for libudev
- Make sure in CMake, you set the INSTALL PREFIX e.g CMAKE_INSTALL_PREFIX or to point to the dist folder in each of the dependencies folder. There is a dist folder there
- To build using CMake GUI, create a folder called build inside each of the dependency's project forder (e.g SFML-master/build), and in CMake GUI set this as where to build the binaries. Click on Configure and after a success, click on Genarate. Once genarating is complete, go to that build folder on a terminal e.g SFML-master and run $ make -j4
- Once done, run $ make install to install in the dist folder
- Once dependencies are build, run $ scons on the root folder of this project
- Run $ ./run.sh to run the program
- Prefer shared libs to static libs if you're new to project building

# Notes
- CMAKE_BUILD_TYPE can be Debug , Release , RelWithDebInfo