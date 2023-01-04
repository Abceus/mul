#include "widgets/mul_label.h"
#include <imgui.h>

void MulLabel::init(const std::string& text_) {
    text = text_;
}

void MulLabel::onDraw() {
    ImGui::Text("%s", text.c_str());
}
