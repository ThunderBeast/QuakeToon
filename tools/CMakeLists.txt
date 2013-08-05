
#fix me, requires libxml2 2.6.24
#./configure --disable-shared CC="gcc -arch i386" CXX="g++ -arch i386"
include_directories(/usr/local/include/libxml2 common)

#common library
file ( GLOB COMMON_SOURCES common/*.c )
set ( COMMON_NET_SOURCES common/l_net/l_net.c common/l_net/l_net_berkeley.c)

file ( GLOB Q2MAP_SOURCES q2map/*.c )
file ( GLOB QDATA_SOURCES qdata/*.c )

add_library (tool_common STATIC ${COMMON_SOURCES} ${COMMON_NET_SOURCES} )

add_executable (q2map ${Q2MAP_SOURCES} )

target_link_libraries(q2map tool_common -lz -liconv -L/usr/local/lib -lxml2 )

get_target_property(q2mapbin q2map LOCATION)

add_custom_command(TARGET q2map
    POST_BUILD
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/bin
    COMMAND cp ${q2mapbin} ${CMAKE_SOURCE_DIR}/bin/q2map
)

