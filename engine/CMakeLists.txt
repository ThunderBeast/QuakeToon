
# Define target name
set ( TARGET_NAME QuakeToon )

add_definitions(-DC_ONLY=1) 

file ( GLOB COMMON_FILES   qcommon/*.c game/q_shared.c game/m_flash.c)
file ( GLOB CLIENT_FILES   client/*.c )
file ( GLOB SERVER_FILES   server/*.c )
file ( GLOB UI_FILES       ui/*.c )
file ( GLOB RENDERER_FILES renderer/*.c )
file ( GLOB SYSTEM_FILES   system/*.c ) 
file ( GLOB SOUND_FILES    sound/*.c )
file ( GLOB SCRIPT_FILES   script/*.c ) 

set ( SOURCE_FILES ${COMMON_FILES} ${SERVER_FILES} ${UI_FILES} ${CLIENT_FILES} ${RENDERER_FILES} ${SOUND_FILES} ${SYSTEM_FILES} ${SCRIPT_FILES} )

if (NOT LINUX)

    set (CMAKE_EXE_LINKER_FLAGS "-lz -framework AudioUnit -framework Carbon -framework Cocoa -framework CoreAudio -framework ForceFeedback -framework IOKit -framework OpenGL -framework CoreServices")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib -lSDL -lSDLmain -L${CMAKE_SOURCE_DIR}/build/luajit_x86/lib -lluajit-5.1" )

    add_executable(QuakeToon ${SOURCE_FILES})

    target_link_libraries(QuakeToon vendor )

    get_target_property(quaketoonbin QuakeToon LOCATION)

    add_custom_command(TARGET QuakeToon
        POST_BUILD
        COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/bin
        COMMAND cp ${quaketoonbin} ${CMAKE_SOURCE_DIR}/bin/QuakeToon
    )
endif()

file ( GLOB GAME_FILES game/*.c game/acesrc/*.c )

add_library( game SHARED ${GAME_FILES} )

get_target_property(gamebin game LOCATION)

add_custom_command(TARGET game
    POST_BUILD
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/bin/baseq2
    COMMAND cp ${gamebin} ${CMAKE_SOURCE_DIR}/bin/baseq2/game.so
)

#dedicated server

set ( SOURCE_FILES ${COMMON_FILES} ${SERVER_FILES} ${SYSTEM_FILES} ${SCRIPT_FILES} )

#if (LINUX)
#    set (CMAKE_EXE_LINKER_FLAGS -lz -ldl -lm -L${CMAKE_SOURCE_DIR}/build/luajit_x86/lib -lluajit-5.1)
#endif()    

add_executable(QuakeToonServer ${SOURCE_FILES})

set_target_properties(QuakeToonServer PROPERTIES COMPILE_DEFINITIONS "DEDICATED_ONLY=1 DC_ONLY=1")

if (LINUX)
    target_link_libraries(QuakeToonServer vendor -lz -ldl -lm )
else()
    target_link_libraries(QuakeToonServer vendor )    
endif()    

get_target_property(serverbin QuakeToonServer LOCATION)

add_custom_command(TARGET QuakeToonServer
    POST_BUILD    
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/bin
    COMMAND cp ${serverbin} ${CMAKE_SOURCE_DIR}/bin/QuakeToonServer
)




