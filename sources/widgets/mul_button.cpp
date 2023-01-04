#include "widgets/mul_button.h"
#include <imgui.h>

void MulButton::onDraw() {
    ImGui::PushID(this);
    if (ImGui::Button(text.c_str(), ImVec2(100, 100))) {
        callbackCollection.call();
    }
    ImGui::PopID();
}

void MulButton::setText(const std::string& newText) {
    text = newText;
}

std::string MulButton::getText() const {
    return text;
}

std::shared_ptr<MulCallbackOwner<>> MulButton::addClickCallback(const std::function<void()>& newCallback) {
    auto result = std::make_shared<MulCallbackOwner<>>(newCallback);
    callbackCollection.addCallback(result);
    return result;
}