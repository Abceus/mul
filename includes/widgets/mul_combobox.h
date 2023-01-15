#pragma once
#include "mul_widget.h"
#include "mul_callback_owner.h"

#include <functional>
#include <string>
#include <vector>

class MulCombobox : public MulWidget {
public:
    MulCombobox() = default;
    void onDraw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}

    void setVariants(const std::vector<std::string>& newVariants);

    std::string getValue() const;
    size_t getIndex() const;

    using ChangeValueCallbackType = std::shared_ptr<MulCallbackOwner<size_t, std::string>>;
    void addChangeValueCallback(ChangeValueCallbackType& outHandler, const std::function<void(size_t, std::string)>& newCallback);
private:
    MulCallbackCollection<size_t, std::string> callbackCollection;

    std::vector<std::string> variants;
    size_t currentIndex = 0;
};