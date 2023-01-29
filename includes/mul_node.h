#pragma once
#include "imgui_internal.h"

class MulNode {
public:
    virtual void draw() = 0;
    virtual void update(float dt) = 0;
};