#include "widgets/mul_checkbox.h"
#include <imgui.h>

void MulCheckbox::onDraw() {
    ImGui::PushID(this);
    if(ImGui::Checkbox("##checkbox", &value)) {
        callbackCollection.call(value);
    }
    ImGui::PopID();
}

void MulCheckbox::addChangeValueCallback(ChangeCalueCallbackType& outHandler, const std::function<void(bool)>& newCallback) {
    outHandler = std::make_shared<MulCallbackOwner<bool>>(newCallback);
    callbackCollection.addCallback(outHandler);
}

void MulCheckbox::setValue(bool newValue) {
    value = newValue;
}

bool MulCheckbox::getValue() const {
    return value;
}
