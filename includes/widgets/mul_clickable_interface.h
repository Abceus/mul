#pragma once
#include <memory>
#include <functional>
#include "mul_callback_owner.h"

class MulClickableInterface {
public:
    using ClickCallbackType = std::shared_ptr<MulCallbackOwner<>>;
    virtual void addClickCallback(ClickCallbackType& outHandler, const std::function<void()>& newCallback) = 0;
};