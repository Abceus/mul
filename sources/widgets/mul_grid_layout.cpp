#include "widgets/mul_grid_layout.h"
#include <imgui.h>
#include <memory>
#include <numeric>

void MulGridLayout::draw() {
    ImGui::PushID(this);

    if (ImGui::BeginTable("##table", columns))
    {
        for(auto i = 0; i < childrens.size(); ++i) {
            auto column = i%columns;
            if(column==0) {
                ImGui::TableNextRow();
            }
            ImGui::TableSetColumnIndex(column);
            childrens[i]->draw();
        }
        ImGui::EndTable();
    }

    onDraw();
    ImGui::PopID();
    updateChildrenList();
}

void MulGridLayout::setColumns(int value) {
    columns = value;
}

int MulGridLayout::getColumns() const {
    return columns;
}
