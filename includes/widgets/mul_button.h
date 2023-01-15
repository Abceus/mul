#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"

#include <functional>
#include <string>

class MulButton : public MulWidget {
public:
    MulButton() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setText(const std::string& newText);
    std::string getText() const;

    using ClickCallbackType = std::shared_ptr<MulCallbackOwner<>>;
    void addClickCallback(ClickCallbackType& outHandler, const std::function<void()>& newCallback);
private:
    MulCallbackCollection<> callbackCollection;
    std::string text;
};