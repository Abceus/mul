// #ifdef _WIN32
//     #define NOMINMAX
//     #include <windows.h>
// #endif
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#ifndef GLEW_STATIC
	#define GLEW_STATIC 
#endif
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>