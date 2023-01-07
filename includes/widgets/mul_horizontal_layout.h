#pragma once
#include "mul_widget.h"

#include <functional>
#include <string>

class MulHorizontalLayout : public MulWidget {
public:
    MulHorizontalLayout() = default;
    void draw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}
    void onDraw() override {}

};