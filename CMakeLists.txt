cmake_minimum_required( VERSION 3.9 )

project( mul )

set( CMAKE_CXX_STANDARD 20 )

set(GLEW_USE_STATIC_LIBS TRUE)
add_subdirectory(3rd_party/glew)
find_package(OpenGL REQUIRED)
add_subdirectory(3rd_party/glfw)
add_subdirectory(3rd_party/stb)
add_subdirectory(3rd_party/imgui)
add_subdirectory(3rd_party/nativefiledialog)

set(mul_sources
    sources/mul_layout.cpp
    sources/mul_widget.cpp
    sources/mul_window.cpp
    sources/mul_context.cpp
    sources/mul_context_holder.cpp
    sources/mul_image.cpp

    sources/widgets/mul_button.cpp
    sources/widgets/mul_label.cpp
    sources/widgets/mul_checkbox.cpp
    sources/widgets/mul_combobox.cpp
    sources/widgets/mul_float_input.cpp
    sources/widgets/mul_file_picker.cpp
    sources/widgets/mul_horizontal_layout.cpp
    sources/widgets/mul_vertical_layout.cpp
    sources/widgets/mul_grid_layout.cpp
    sources/widgets/mul_splitter.cpp
    sources/widgets/mul_opengl_canvas.cpp
)

add_library(mul ${mul_sources})

target_include_directories( mul
        PUBLIC includes
        PUBLIC ${GLEW_INCLUDE_DIR})

target_link_libraries( mul glew_s glfw OpenGL::GL stb imgui nfd)

add_executable(mul_test sources/main.cpp)

target_link_libraries(mul_test mul)