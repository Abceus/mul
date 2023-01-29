#pragma once
#include "mul_layout.h"
#include "mul_widget.h"

#include <functional>
#include <string>

class MulVerticalLayout : public MulLayout {
public:
    MulVerticalLayout() = default;
    void draw() override;
};