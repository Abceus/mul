#include "widgets/mul_horizontal_layout.h"
#include "mul_widget.h"
#include <imgui.h>
#include <memory>
#include <numeric>

void MulHorizontalLayout::draw() {
    auto availableSpace = ImGui::GetContentRegionAvail().x;
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
    auto startCursorPosition = ImGui::GetCursorPos().x;
    for(const auto& child: childrens) {
        auto currentItemWIdth = child->getFitPolicy() == FitPolicy::Fix ? child->getWidth() : availableSpace*(child->getFillHorizontalSpace()/allHorizontalSpace);
        ImGui::SetCursorPosX(startCursorPosition+skipedSpace);
        child->setWidth(currentItemWIdth);
        child->draw();
        skipedSpace += currentItemWIdth;
        ImGui::SameLine();
    }
    ImGui::NewLine();
    onDraw();
}
