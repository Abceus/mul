#include "widgets/mul_file_picker_base.h"
#include "mul_size_strategy.h"
#include "mul_widget.h"
#include "widgets/mul_button.h"
#include "widgets/mul_horizontal_layout.h"
#include "widgets/mul_label.h"
#include "mul_size_strategy.h"
#include <filesystem>
#include <imgui.h>
#include <memory>
#include <nfd.h>


void MulFilePickerBase::initFilePicker() {
    pathLabel->setText(currentPath.string());

    button->addClickCallback(buttonCallback, [this](){
        nfdchar_t *outPath = NULL;
        nfdresult_t result = NFD_OpenDialog( filter.empty() ? nullptr : filter.c_str(), NULL, &outPath );
            
        if ( result == NFD_OKAY ) {
            currentPath = outPath;
            free(outPath);

            pathLabel->setText(currentPath.string());
            callbackCollection.call(currentPath.string());
        }
        // else if ( result == NFD_CANCEL ) {
        //     std::cout << "User pressed cancel." << std::endl;
        // }
        // else {
        //     std::cout << "Error: " << NFD_GetError() << std::endl;
        // }
    });
}

void MulFilePickerBase::setFilter(const std::string& filter_) {
    filter = filter_;
}

void MulFilePickerBase::addChangePathCallback(ChangePathCallbackType& outHandler, const std::function<void(std::filesystem::path)>& newCallback) {
    outHandler = std::make_shared<MulCallbackOwner<std::filesystem::path>>(newCallback);
    callbackCollection.addCallback(outHandler);
}