#include "widgets/mul_horizontal_layout.h"
#include "mul_size_strategy.h"
#include "mul_widget.h"
#include <imgui.h>
#include <memory>
#include <numeric>

void MulHorizontalLayout::draw() {
    auto availableWidth = availableSpace.getX();
    float allHorizontalSpace = 0.0f;

    for(const auto& child: childrens) {
        if(child->getHorizontalFitPolicy().type == MulFitType::Fix) {
            auto width = std::max(child->getMinimumWidth(), child->getHorizontalFitPolicy().size);
            if(child->getMaximumWidth() != MulWidget::UNSET_MAXIMUM_VALUE) {
                width = std::min(width, child->getMaximumWidth());
            }
            availableWidth -= width;
        } else {
            allHorizontalSpace += child->getHorizontalFitPolicy().proportion;
        }
    }

    auto skipedSpace = 0.0f;
    auto startCursorPosition = ImGui::GetCursorPos().x;
    for(auto i = 0; i < childrens.size(); ++i) {
        auto& child = childrens[i];
        auto proportion = child->getHorizontalFitPolicy().proportion / allHorizontalSpace;
        auto currentItemWidth = child->getHorizontalFitPolicy().type == MulFitType::Fix ? child->getHorizontalFitPolicy().size : static_cast<int>(availableWidth*proportion);
        auto nonNormWidth = currentItemWidth;
        bool changed = false;
        if(child->getMinimumWidth() > currentItemWidth) {
            currentItemWidth = child->getMinimumWidth();
            changed = true;
        }
        else if(child->getMaximumWidth() != MulWidget::UNSET_MAXIMUM_VALUE && child->getMaximumWidth() < currentItemWidth) {
            currentItemWidth = child->getMaximumWidth();
            changed = true;
        }

        if(changed) {
            auto newProportion = currentItemWidth / availableWidth;
            allHorizontalSpace += newProportion - proportion;
            availableWidth += currentItemWidth - nonNormWidth;
        }

        ImGui::SetCursorPosX(startCursorPosition+skipedSpace);
        child->setWidth(currentItemWidth);
        child->setHeight(availableSpace.getY());
        child->draw();
        skipedSpace += currentItemWidth;
        ImGui::SameLine();
    }
    ImGui::NewLine();
    updateChildrenList();
}
