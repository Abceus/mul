#include "widgets/mul_splitter.h"
#include "mul_widget.h"
#include <imgui.h>
#include <memory>

void MulSplitter::draw() {
    ImGui::PushID(this);

    if (ImGui::BeginTable("##table", 2, ImGuiTableFlags_Resizable))
    {
        if(firstWidget)
        {
            ImGui::TableNextColumn();
            firstWidget->draw();
        }
        if(secondWidget)
        {
            ImGui::TableNextColumn();
            secondWidget->draw();
        }
        ImGui::EndTable();
    }

    onDraw();
    ImGui::PopID();
}

void MulSplitter::setFirstWidget(const std::shared_ptr<MulWidget>& newWidget) {
    firstWidget = newWidget;
}

std::shared_ptr<MulWidget> MulSplitter::getFirstWidget() const {
    return firstWidget;
}

void MulSplitter::setSecondWidget(const std::shared_ptr<MulWidget>& newWidget) {
    secondWidget = newWidget;
}

std::shared_ptr<MulWidget> MulSplitter::getSecondWidget() const {
    return secondWidget;
}
