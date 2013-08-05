# Set project name
project (QuakeToon)

# Set minimum version
cmake_minimum_required (VERSION 2.8)

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
    message("Linux Build")
    set (LINUX 1)
endif()

#32 bit for now
set(CMAKE_OSX_ARCHITECTURES "i386")

# Add SDL as a global include directory
#FIXME, build SDL in source tree once 2.0 is stable (see Urho3D build)
include_directories(/usr/local/include/SDL)
include_directories( build/luajit_x86/include/luajit-2.0 vendor/lpeg vendor/unzip vendor/luafilesystem)


# Add targets
add_subdirectory (vendor)
add_subdirectory (engine)
add_subdirectory (tools)
