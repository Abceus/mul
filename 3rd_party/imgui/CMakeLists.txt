cmake_minimum_required( VERSION 3.9 )

project( imgui )

set( CMAKE_CXX_STANDARD 20 )

set( imgui_sources
    imgui/imgui.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_draw.cpp
    
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp)

add_library( imgui STATIC ${imgui_sources} )

target_include_directories( imgui PUBLIC imgui )

target_link_libraries( imgui glfw ) #rework