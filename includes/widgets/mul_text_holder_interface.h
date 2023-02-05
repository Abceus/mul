#pragma once
#include <string>

class MulTextHolderInterface {
public:
    virtual void setText(const std::string& value) = 0;
    virtual std::string getText() const = 0;
};