#pragma once
#include "mul_widget.h"
#include "mul_text_holder_interface.h"
#include "widgets/mul_text_holder_interface.h"

#include <functional>
#include <string>

class MulLabel : public MulWidget, public MulTextHolderInterface {
public:
    MulLabel() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setText(const std::string& text) override;
    std::string getText() const override;
    
private:
    std::string text;
};