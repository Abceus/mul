#include "widgets/mul_vertical_layout.h"
#include "mul_widget.h"
#include <imgui.h>
#include <memory>
#include <numeric>

void MulVerticalLayout::draw() {
    auto availableSpace = ImGui::GetContentRegionAvail().y;
    float allVerticalSpace = 0.0f;
    for(const auto& child: childrens) {
        // if(child->getFitPolicy() == FitPolicy::Fix) {
        //     availableSpace -= child->getHeight();
        // }
        // else {
        //     allVerticalSpace += child->getFillVerticalSpace();
        // }
    }
    auto skipedSpace = 0.0f;
    auto startCursorPosition = ImGui::GetCursorPos().y;
    for(const auto& child: childrens) {
        //auto currentItemHeight = child->getFitPolicy() == FitPolicy::Fix ? child->getHeight() : availableSpace*(child->getFillVerticalSpace()/allVerticalSpace);
        //ImGui::SetCursorPosY(startCursorPosition+skipedSpace);
        //child->setHeight(currentItemHeight);
        child->draw();
        //skipedSpace += currentItemHeight;
    }
    updateChildrenList();
}
