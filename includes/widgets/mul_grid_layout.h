#pragma once
#include "mul_widget.h"

#include <functional>
#include <string>

class MulGridLayout : public MulWidget {
public:
    MulGridLayout() = default;
    void draw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}
    void onDraw() override {}

    void setColumns(int value);
    int getColumns() const;
protected:
    int columns = 1;
};