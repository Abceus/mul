#include "mul_window.h"
#include "mul_opengl.h"
#include "mul_context.h"

void MulWindow::init(const std::string& title, const Vec2I& size) {
    if(!m_window) {
        MulContext::getCurrentContext().registerWindow(this);
        m_window = glfwCreateWindow(size.getX(), size.getY(), title.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window){ 
            static_cast<MulWindow*>(glfwGetWindowUserPointer(window))->deinit(); 
        });
        glfwMakeContextCurrent(m_window);
    } else {
        glfwSetWindowTitle(m_window, title.c_str());
        glfwSetWindowSize(m_window, size.getX(), size.getY());
    }
    glewInit();
    MulWidget::init();
}

void MulWindow::deinit() {
    if(m_window) {
        MulContext::getCurrentContext().unregisterWindow(this);
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
}

void MulWindow::draw() {
    if(m_window) {        
        MulWidget::draw();

        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_window);
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

void MulWindow::onDraw() {}

void MulWindow::onUpdate(float dt) {}
