#pragma once
#include "mul_layout.h"
#include "mul_widget.h"

#include <functional>
#include <string>

class MulHorizontalLayout : public MulLayout {
public:
    MulHorizontalLayout() = default;
    void draw() override;
};