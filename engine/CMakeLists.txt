
# Define target name
set ( TARGET_NAME QuakeToon )

add_definitions(-DC_ONLY=1)

#file ( GLOB COMMON_FILES   qcommon/*.c )
#file ( GLOB CLIENT_FILES   client/*.c )
#file ( GLOB SERVER_FILES   server/*.c )
#file ( GLOB GAME_FILES     game/*.c )
#file ( GLOB UI_FILES       ui/*.c )
file ( GLOB RENDERER_FILES  renderer/*.c )

set ( SOURCE_FILES ${COMMON_FILES} ${SERVER_FILES} ${GAME_FILES} ${UI_FILES} ${CLIENT_FILES} ${RENDERER_FILES} )

add_executable(QuakeToon ${SOURCE_FILES})
set (CMAKE_EXE_LINKER_FLAGS "-framework AudioUnit -framework Carbon -framework Cocoa -framework CoreAudio -framework ForceFeedback -framework IOKit -framework OpenGL -framework CoreServices")

#target_link_libraries(QuakeToon unzip SDL STB -lz)

