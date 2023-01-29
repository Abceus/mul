#pragma once
#include "mul_layout.h"
#include "mul_widget.h"

#include <functional>
#include <string>

class MulGridLayout : public MulLayout {
public:
    MulGridLayout() = default;
    void draw() override;

    void setColumns(int value);
    int getColumns() const;
protected:
    int columns = 1;
};