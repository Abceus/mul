#include "widgets/mul_float_input.h"
#include <imgui.h>

void MulFloatInput::onDraw() {
    ImGui::PushID(this);
    
    ImGui::InputFloat("##floatinput", &value, 0.1f);

    if(ImGui::IsItemDeactivatedAfterEdit()) {
        callbackCollection.call(value);
    }
    ImGui::PopID();
}

std::shared_ptr<MulCallbackOwner<float>> MulFloatInput::addChangeValueCallback(const std::function<void(float)>& newCallback) {
    auto result = std::make_shared<MulCallbackOwner<float>>(newCallback);
    callbackCollection.addCallback(result);
    return result;
}

void MulFloatInput::setValue(float newValue) {
    value = newValue;
}

float MulFloatInput::getValue() const {
    return value;
}
