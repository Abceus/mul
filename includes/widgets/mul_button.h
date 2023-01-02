#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"

#include <functional>

class MulButton : public MulWidget {
public:
    MulButton() = default;
    void onDraw() const override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    std::shared_ptr<MulCallbackOwner<>> addClickCallback(const std::function<void()>& newCallback);
private:
    MulCallbackCollection<> callbackCollection;
};