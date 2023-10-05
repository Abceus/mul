#pragma once
#include "mul_vec2.h"

#include <string>

#include "mul_opengl.h"
#include "mul_widget.h"

class MulWindow : public MulWidget {
public:
    virtual ~MulWindow() = default;
    
    void init(const std::string& title, const Vec2I& size);
    void deinit();

    void draw() override;
    
    void show();
    void hide();

    bool isClosed() const;

    void onInit() override;
    void onDraw() override;
    void onUpdate(float dt) override;

private:
    GLFWwindow* m_window = nullptr;
    bool closed = false;
};
