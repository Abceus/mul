#pragma once
#include "mul_widget.h"

#include <functional>
#include <string>

class MulOpenglCanvas : public MulWidget {
public:
    MulOpenglCanvas() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override;
    
    virtual void glDraw();

    void setDrawFunction(const std::function<void()>& value);

protected:
    std::function<void()> drawFunction;

    unsigned int frameBufferId = 0;
    unsigned int renderedTexture = 0;
};