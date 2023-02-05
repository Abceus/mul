#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"
#include "mul_clickable_interface.h"
#include "mul_text_holder_interface.h"
#include "widgets/mul_clickable_interface.h"
#include "widgets/mul_text_holder_interface.h"

#include <functional>
#include <string>

class MulButton : public MulWidget, 
                    public MulTextHolderInterface, 
                    public MulClickableInterface {
public:
    MulButton() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setText(const std::string& newText) override;
    std::string getText() const override;

    using ClickCallbackType = std::shared_ptr<MulCallbackOwner<>>;
    void addClickCallback(ClickCallbackType& outHandler, const std::function<void()>& newCallback) override;
private:
    MulCallbackCollection<> callbackCollection;
    std::string text;
};