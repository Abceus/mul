#include "widgets/mul_label.h"
#include <imgui.h>


void MulLabel::onDraw() {
    ImGui::Text("%s", text.c_str());
}

void MulLabel::setText(const std::string& _text) {
    text = _text;
}

std::string MulLabel::getText() const {
    return text;
}