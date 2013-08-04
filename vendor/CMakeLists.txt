

set ( UNZIP_SOURCES unzip/ioapi.c unzip/unzip.c )
set ( LUAFILESYSTEM_SOURCES luafilesystem/lfs.c )
file ( GLOB LPEG_SOURCES lpeg/*.c)

add_library (vendor STATIC ${UNZIP_SOURCES} ${LPEG_SOURCES} ${LUAFILESYSTEM_SOURCES} )

if (LINUX)
    target_link_libraries(vendor -lz -L${CMAKE_SOURCE_DIR}/build/luajit_x86/lib -lluajit-5.1)
endif()    
