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

void MulFloatInput::addChangeValueCallback(ChangeValueCallbackType& outHandler, const std::function<void(float)>& newCallback) {
    outHandler = std::make_shared<MulCallbackOwner<float>>(newCallback);
    callbackCollection.addCallback(outHandler);
}

void MulFloatInput::setValue(float newValue) {
    value = newValue;
}

float MulFloatInput::getValue() const {
    return value;
}
