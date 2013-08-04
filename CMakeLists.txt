# Set project name
project (QuakeToon)

# Set minimum version
cmake_minimum_required (VERSION 2.8)

#32 bit for now
set(CMAKE_OSX_ARCHITECTURES "i386")

# Add SDL as a global include directory
#include_directories (vendor/SDL/include)
#include_directories (vendor/STB)
#include_directories (vendor/unzip)

include_directories( build/luajit_x86/include/luajit-2.0 )

# Add targets
add_subdirectory (vendor)
add_subdirectory (engine)
