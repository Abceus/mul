#include "widgets/mul_float_input.h"

void MulFloatInput::onDraw() {
    if(false) { // edited
        callbackCollection.call(value);
    }
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
