#include "widgets/mul_splitter.h"
#include "mul_widget.h"
#include <imgui.h>
#include <memory>

void MulSplitter::draw() {
    ImGui::PushID(this);

    const auto prevAvailable = ImGui::GetContentRegionAvail();
    const auto prevCursor = ImGui::GetCursorPos();

    if (ImGui::BeginTable("##table", 2, ImGuiTableFlags_Resizable))
    {
        if(firstWidget)
        {
            ImGui::TableNextColumn();
            const auto width = ImGui::GetColumnWidth();
            firstWidget->setWidth(width);
            firstWidget->draw();
        }
        if(secondWidget)
        {
            ImGui::TableNextColumn();
            const auto width = ImGui::GetColumnWidth();
            secondWidget->setWidth(width);
            secondWidget->draw();
        }
        ImGui::EndTable();
    }

    onDraw();

    const auto postAvailable = ImGui::GetContentRegionAvail();
    const auto postCursor = ImGui::GetCursorPos();
    size = Vec2I(prevAvailable.x, postCursor.y-prevCursor.y);

    ImGui::PopID();
}

void MulSplitter::onKeyPressed(const ImGuiInputEvent& event) {
    if(firstWidget) {
        firstWidget->onKeyPressed(event);
    }

    if(secondWidget) {
        secondWidget->onKeyPressed(event);
    }
}

void MulSplitter::setFirstWidget(const std::shared_ptr<MulWidget>& newWidget) {
    firstWidget = newWidget;

    // if(childrens.size() >= 1) {
    //     if(newWidget) {
    //         childrens[0] = firstWidget;
    //     }
    //     else {
    //         removeChild(0);
    //     }
    //     return;
    // }

    // if(firstWidget) {
    //     childrens.emplace_back(firstWidget);
    // }
    // else {
    //     childrens.clear();
    // }
}

std::shared_ptr<MulWidget> MulSplitter::getFirstWidget() const {
    return firstWidget;
}

void MulSplitter::setSecondWidget(const std::shared_ptr<MulWidget>& newWidget) {
    secondWidget = newWidget;

    // if(childrens.size() >= 2) {
    //     if(newWidget) {
    //         childrens[1] = secondWidget;
    //     }
    //     else {
    //         removeChild(1);
    //     }
    //     return;
    // }

    // if(secondWidget) {
    //     childrens.emplace_back(secondWidget);
    // }
    // else {
    //     childrens.resize(1);
    // }
}

std::shared_ptr<MulWidget> MulSplitter::getSecondWidget() const {
    return secondWidget;
}

MulWidget* MulSplitter::getWidgetByPosition(const Vec2I& position) {
    if(firstWidget) {
        if(const auto result = firstWidget->getWidgetByPosition(position)) {
            return result;
        }
    }
    if(secondWidget) {
        if(const auto result = secondWidget->getWidgetByPosition(position)) {
            return result;
        }
    }

    return this;
}