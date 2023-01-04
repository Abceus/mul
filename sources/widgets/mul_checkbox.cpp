#include "widgets/mul_checkbox.h"
#include <imgui.h>

void MulCheckbox::onDraw() {
    ImGui::PushID(this);
    if(ImGui::Checkbox("##checkbox", &value)) {
        callbackCollection.call(value);
    }
    ImGui::PopID();
}

std::shared_ptr<MulCallbackOwner<bool>> MulCheckbox::addChangeValueCallback(const std::function<void(bool)>& newCallback) {
    auto result = std::make_shared<MulCallbackOwner<bool>>(newCallback);
    callbackCollection.addCallback(result);
    return result;
}

void MulCheckbox::setValue(bool newValue) {
    value = newValue;
}

bool MulCheckbox::getValue() const {
    return value;
}
