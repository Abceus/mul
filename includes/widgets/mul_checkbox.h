#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"

#include <functional>
#include <string>

class MulCheckbox : public MulWidget {
public:
    MulCheckbox() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setValue(bool newValue);
    bool getValue() const;

    using ChangeCalueCallbackType = std::shared_ptr<MulCallbackOwner<bool>>;
    void addChangeValueCallback(ChangeCalueCallbackType& outHandler, const std::function<void(bool)>& newCallback);
private:
    MulCallbackCollection<bool> callbackCollection;

    bool value = false;
};