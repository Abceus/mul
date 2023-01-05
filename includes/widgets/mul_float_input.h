#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"

#include <functional>

class MulFloatInput : public MulWidget {
public:
    MulFloatInput() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setValue(float newValue);
    float getValue() const;

    std::shared_ptr<MulCallbackOwner<float>> addChangeValueCallback(const std::function<void(float)>& newCallback);
private:
    MulCallbackCollection<float> callbackCollection;

    float value = 0.0f;
};