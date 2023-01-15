#pragma once
#include "mul_concepts.h"
#include "mul_widget.h"

#include <memory>

template<Derived<MulWidget> T>
std::shared_ptr<T> MulMakeWidget(auto&&... args) {
    auto result = std::make_shared<T>();
    result->init(std::forward<decltype(args)>(args)...);
    result->onInit();
    return result;
}
