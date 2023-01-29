#include "widgets/mul_label.h"
#include <imgui.h>


void MulLabel::onDraw() {
    ImGui::PushItemWidth(getWidth());
    ImGui::Text("%s", text.c_str());
    ImGui::PopItemWidth();
}

void MulLabel::setText(const std::string& _text) {
    text = _text;
}

std::string MulLabel::getText() const {
    return text;
}