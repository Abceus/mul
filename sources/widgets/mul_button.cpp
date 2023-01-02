#include "widgets/mul_button.h"
#include <imgui.h>

void MulButton::onDraw() const {
    if (ImGui::Button("Test", ImVec2(100, 100))) {
        callbackCollection.call();
    }
}

std::shared_ptr<MulCallbackOwner<>> MulButton::addClickCallback(const std::function<void()>& newCallback) {
    auto result = std::make_shared<MulCallbackOwner<>>(newCallback);
    callbackCollection.addCallback(result);
    return result;
}