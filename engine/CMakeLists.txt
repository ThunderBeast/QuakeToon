
# Define target name
set ( TARGET_NAME QuakeToon )

add_definitions(-DC_ONLY=1) 

#FIXME
include_directories(/usr/local/include/SDL)

file ( GLOB COMMON_FILES   qcommon/*.c game/q_shared.c game/m_flash.c)
file ( GLOB CLIENT_FILES   client/*.c )
file ( GLOB SERVER_FILES   server/*.c )
file ( GLOB UI_FILES       ui/*.c )
file ( GLOB RENDERER_FILES renderer/*.c )
file ( GLOB SYSTEM_FILES   system/*.c ) 
file ( GLOB SOUND_FILES    sound/*.c ) 

set ( SOURCE_FILES ${COMMON_FILES} ${SERVER_FILES} ${UI_FILES} ${CLIENT_FILES} ${RENDERER_FILES} ${SOUND_FILES} ${SYSTEM_FILES} )

add_executable(QuakeToon ${SOURCE_FILES})
set (CMAKE_EXE_LINKER_FLAGS "-lz -framework AudioUnit -framework Carbon -framework Cocoa -framework CoreAudio -framework ForceFeedback -framework IOKit -framework OpenGL -framework CoreServices")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib -lSDL -lSDLmain" )

target_link_libraries(QuakeToon vendor )


file ( GLOB GAME_FILES     game/*.c game/acesrc/*.c )

