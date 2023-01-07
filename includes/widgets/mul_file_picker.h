#pragma once
#include "mul_widget.h"
#include "widgets/mul_button.h"
#include "widgets/mul_label.h"

#include <filesystem>
#include <functional>
#include <memory>
#include <string>

class MulFilePicker : public MulWidget {
public:
    MulFilePicker() = default;
    void onDraw() override {} ;

    void onUpdate(float dt) override {}
    void onInit() override;

    [[nodiscard]]
    std::shared_ptr<MulCallbackOwner<std::filesystem::path>> addChangePathCallback(const std::function<void(std::filesystem::path)>& newCallback);
private:
    std::shared_ptr<MulButton> button;
    std::shared_ptr<MulLabel> pathLabel;

    std::shared_ptr<MulCallbackOwner<>> buttonCallback;

    MulCallbackCollection<std::filesystem::path> callbackCollection;
};