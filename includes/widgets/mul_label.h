#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"

#include <functional>
#include <string>

class MulLabel : public MulWidget {
public:
    MulLabel() = default;
    void init(const std::string& text);
    void onDraw() const override;

    void onUpdate(float dt) override {}
    void onInit() override {}

private:
    std::string text;
};