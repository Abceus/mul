#include "widgets/mul_checkbox.h"

void MulCheckbox::onDraw() {
    if(false) { // pressed
        callbackCollection.call(value);
    }
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
