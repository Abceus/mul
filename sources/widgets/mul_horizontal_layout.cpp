#include "widgets/mul_horizontal_layout.h"
#include "mul_widget.h"
#include <memory>
#include <numeric>

void MulHorizontalLayout::draw() {
    auto availableSpace = 100; // space
    float allHorizontalSpace = 0.0f;
    for(const auto& child: childrens) {
        if(child->getFitPolicy() == FitPolicy::Fix) {
            availableSpace -= child->getWidth();
        }
        else {
            allHorizontalSpace += child->getFillHorizontalSpace();
        }
    }
    auto skipedSpace = 0.0f;
    auto startCursorPosition = 10; // current
    for(const auto& child: childrens) {
        auto currentItemWIdth = child->getFitPolicy() == FitPolicy::Fix ? child->getWidth() : availableSpace*(child->getFillHorizontalSpace()/allHorizontalSpace);
        // SetCursorPosX(startCursorPosition+skipedSpace);
        child->setWidth(currentItemWIdth);
        child->draw();
        skipedSpace += currentItemWIdth;
    }
    onDraw();
}
