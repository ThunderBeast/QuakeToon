

set ( UNZIP_SOURCES unzip/ioapi.c unzip/unzip.c )
set ( LUAFILESYSTEM_SOURCES luafilesystem/lfs.c )
file ( GLOB LPEG_SOURCES lpeg/*.c)

add_library (vendor STATIC ${UNZIP_SOURCES} ${LPEG_SOURCES} ${LUAFILESYSTEM_SOURCES} )