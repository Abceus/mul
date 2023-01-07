cmake_minimum_required( VERSION 3.9 )

project( nfd )

set( nfd_sources
        nativefiledialog/src/nfd_common.c )

if( WIN32 )
    set( nfd_sources ${nfd_sources} nativefiledialog/src/nfd_win.cpp )
elseif( LINUX )
    set( nfd_sources ${nfd_sources} nativefiledialog/src/nfd_zenity.cpp )
endif()

add_library( nfd STATIC ${nfd_sources} )

target_include_directories( nfd 
    PRIVATE nativefiledialog/src
    PUBLIC nativefiledialog/src/include )
