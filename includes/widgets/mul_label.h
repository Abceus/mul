#pragma once
#include "mul_widget.h"

#include <functional>
#include <string>

class MulLabel : public MulWidget {
public:
    MulLabel() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setText(const std::string& text);
    std::string getText() const;
    
private:
    std::string text;
};