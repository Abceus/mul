cmake_minimum_required( VERSION 3.9 )

project( mul )

set( CMAKE_CXX_STANDARD 20 )

add_subdirectory(3rd_party/glfw)

set(mul_sources
    sources/mul_window.cpp
    sources/mul_context.cpp
    sources/mul_context_holder.cpp
)

add_library(mul ${mul_sources})

target_include_directories( mul
        PUBLIC includes)

target_link_libraries( mul glfw )

add_executable(mul_test sources/main.cpp)

target_link_libraries(mul_test mul)