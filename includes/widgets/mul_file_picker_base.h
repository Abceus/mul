#pragma once
#include "mul_widget.h"
#include "widgets/mul_clickable_interface.h"
#include "widgets/mul_text_holder_interface.h"

#include <filesystem>
#include <functional>
#include <memory>
#include <string>

class MulFilePickerBase : public MulWidget {
public:
    virtual void initFilePicker();

    virtual void setFilter(const std::string& filter);

    using ChangePathCallbackType = std::shared_ptr<MulCallbackOwner<std::filesystem::path>>;
    virtual void addChangePathCallback(ChangePathCallbackType& outHandler, const std::function<void(std::filesystem::path)>& newCallback);
protected:
    std::shared_ptr<MulClickableInterface> button;
    std::shared_ptr<MulTextHolderInterface> pathLabel;

    MulClickableInterface::ClickCallbackType buttonCallback;

    MulCallbackCollection<std::filesystem::path> callbackCollection;

    std::string filter;
    std::filesystem::path currentPath;
};