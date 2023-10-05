#include "mul_window.h"
#include "imgui.h"
#include "mul_opengl.h"
#include "mul_context.h"
#include "mul_vec2.h"

void MulWindow::init(const std::string& title, const Vec2I& size) {
    if(!m_window) {
        MulContext::getCurrentContext().registerWindow(this);
        m_window = glfwCreateWindow(size.getX(), size.getY(), title.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_window, this);
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window){ 
            static_cast<MulWindow*>(glfwGetWindowUserPointer(window))->deinit(); 
        });
        glfwMakeContextCurrent(m_window);
        ImGui_ImplGlfw_InitForOpenGL(m_window, true);
        ImGui_ImplOpenGL3_Init("#version 130");
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
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

#ifdef IMGUI_HAS_VIEWPORT
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->GetWorkPos());
        ImGui::SetNextWindowSize(viewport->GetWorkSize());
        ImGui::SetNextWindowViewport(viewport->ID);
#else 
        ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f));
        ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
#endif
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);

        ImGui::Begin("Hello, world!", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize);
        const auto windowSize = ImGui::GetWindowSize();
        size = Vec2I(windowSize.x, windowSize.y);
        MulWidget::draw();
        ImGui::End();
        ImGui::PopStyleVar();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        //glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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
