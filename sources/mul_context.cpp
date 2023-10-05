#include "mul_context.h"
#include "imgui_internal.h"
#include "mul_opengl.h"
#include <iostream>
#include "imgui.h"
#include "mul_vec2.h"

void MulContext::init() {
    if (!glfwInit()) {
        std::cerr << "[ERROR] Couldn't initialize GLFW\n";
    } else {
        std::cout << "[INFO] GLFW initialized\n";
    }

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

    glfwSwapInterval(1);
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    // io.WantCaptureMouse
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();
}

void MulContext::deinit() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    clearWindows();
    glfwTerminate();
}

void MulContext::run() {
    while(!m_windows.empty()) {
        for(auto it = std::begin(m_windows); it != std::end(m_windows);) {
            if((*it)->isClosed()) {
                it = m_windows.erase(it);
            } else {
                for(const auto& event: ImGui::GetCurrentContext()->InputEventsQueue) {
                    if(event.Type == ImGuiInputEventType::ImGuiInputEventType_Key && event.Key.Down) {
                        (*it)->onKeyPressed(event);
                    }
                    else if(event.Type == ImGuiInputEventType_MouseButton && event.MouseButton.Down) {
                        if(event.MouseButton.Button == ImGuiMouseButton_Left) {
                            auto position = ImGui::GetMousePos();
                            if(auto newFocusedWidget = (*it)->getWidgetByPosition({static_cast<int>(position.x), static_cast<int>(position.y)})) {
                                newFocusedWidget->onMouseClickEvent(event);
                            }
                        }
                    }
                    else if(event.Type == ImGuiInputEventType_MousePos) {
                        (*it)->onMouseMoveEvent(event);
                    }
                    else if(event.Type == ImGuiInputEventType_MouseWheel) {
                        (*it)->onMouseScrollEvent(event);
                    }
                }
                (*it)->draw();
                (*it)->update(0.1f);
                ++it;
            }
        }
        glfwPollEvents();
    }
}

void MulContext::clearWindows() {
    for(auto it = std::begin(m_windows); it != std::end(m_windows);) {
        delete *it;
    }
    m_windows.clear();
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