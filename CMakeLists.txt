# Set project name
project (QuakeToon)

# Set minimum version
cmake_minimum_required (VERSION 2.8)

#32 bit for now
set(CMAKE_OSX_ARCHITECTURES "i386")

# Add SDL as a global include directory
include_directories (vendor/SDL/include)
include_directories (vendor/STB)
include_directories (vendor/unzip)

# Add targets
add_subdirectory (vendor)
add_subdirectory (engine)
