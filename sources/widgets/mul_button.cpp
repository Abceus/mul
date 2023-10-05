#include "widgets/mul_button.h"

void MulButton::onDraw() {
    if (false) { // pressed
        callbackCollection.call();
    }
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