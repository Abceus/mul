#include "widgets/mul_button.h"
#include <imgui.h>

void MulButton::onDraw() {
    ImGui::PushID(this);
    if (ImGui::Button(text.c_str(), ImVec2(getWidth(), getHeight()))) {
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

void MulButton::addClickCallback(ClickCallbackType& outHandler, const std::function<void()>& newCallback) {
    outHandler = std::make_shared<MulCallbackOwner<>>(newCallback);
    callbackCollection.addCallback(outHandler);
}