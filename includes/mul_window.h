#pragma once
#include "mul_vec2.h"

#include <string>

#include <GLFW/glfw3.h>

class MulWindow {
public:
    void init(const std::string& title, const Vec2I& size);
    void deinit();
    
    void show();
    void hide();

    bool isClosed() const;

    virtual void onInit();

private:
    GLFWwindow* m_window = nullptr;
    bool closed = false;
};
