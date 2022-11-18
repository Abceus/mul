#include "mul_window.h"
#include "GLFW/glfw3.h"
#include "mul_context.h"

void MulWindow::init(const std::string& title, const Vec2I& size) {
    if(!m_window) {
        MulContext::getCurrentContext().registerWindow(this);
        m_window = glfwCreateWindow(size.getX(), size.getY(), title.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window){ 
            static_cast<MulWindow*>(glfwGetWindowUserPointer(window))->deinit(); 
        });
    } else {
        glfwSetWindowTitle(m_window, title.c_str());
        glfwSetWindowSize(m_window, size.getX(), size.getY());
    }
    onInit();
}

void MulWindow::deinit() {
    if(m_window) {
        MulContext::getCurrentContext().unregisterWindow(this);
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
}

void MulWindow::show() {
    if(m_window) {
        glfwShowWindow(m_window);
    }
}

void MulWindow::hide() {
    if(m_window) {
        glfwHideWindow(m_window);
    }
}

bool MulWindow::isClosed() const {
    return !m_window || glfwWindowShouldClose(m_window);
}

void MulWindow::onInit() {}
