

set ( UNZIP_SOURCES unzip/ioapi.c unzip/unzip.c )

add_library (vendor STATIC ${UNZIP_SOURCES})