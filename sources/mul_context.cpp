#include "mul_context.h"
#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include <iostream>

void MulContext::init() {
    if (!glfwInit()) {
        std::cerr << "[ERROR] Couldn't initialize GLFW\n";
    } else {
        std::cout << "[INFO] GLFW initialized\n";
    }

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

    glfwSwapInterval(1);
}

void MulContext::run() {
    while(!m_windows.empty()) {
        glfwPollEvents();

        for(auto it = std::begin(m_windows); it != std::end(m_windows);) {
            if((*it)->isClosed()) {
                it = m_windows.erase(it);
            } else {
                ++it;
            }
        }
    }
}

MulContext& MulContext::getCurrentContext() {
    static MulContext context;
    return context;
}

void MulContext::registerWindow(MulWindow* window) {
    m_windows.insert(window);
}

void MulContext::unregisterWindow(MulWindow* window) {
    m_windows.erase(window);
}