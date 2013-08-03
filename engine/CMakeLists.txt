
# Define target name
set ( TARGET_NAME QuakeToon )

file ( GLOB COMMON_FILES   qcommon/*.c )
file ( GLOB SERVER_FILES   server/*.c )

set ( SOURCE_FILES ${COMMON_FILES} ${SERVER_FILES} )

add_executable(QuakeToon ${SOURCE_FILES})
set (CMAKE_EXE_LINKER_FLAGS "-framework AudioUnit -framework Carbon -framework Cocoa -framework CoreAudio -framework ForceFeedback -framework IOKit -framework OpenGL -framework CoreServices")

#target_link_libraries(QuakeToon unzip SDL STB -lz)

