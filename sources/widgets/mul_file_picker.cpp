#include "widgets/mul_file_picker.h"
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


void MulFilePicker::onInit() {
    auto layout = std::make_shared<MulHorizontalLayout>();
    setLayout(layout);

    pathLabel = std::make_shared<MulLabel>();
    layout->addChild(pathLabel);

    button = std::make_shared<MulButton>();
    button->setText("Select");
    button->addClickCallback(buttonCallback, [this](){
        nfdchar_t *outPath = NULL;
        nfdresult_t result = NFD_OpenDialog( filter.empty() ? nullptr : filter.c_str(), NULL, &outPath );
            
        if ( result == NFD_OKAY ) {
            pathLabel->setText(outPath);
            callbackCollection.call(outPath);
            free(outPath);
        }
        // else if ( result == NFD_CANCEL ) {
        //     std::cout << "User pressed cancel." << std::endl;
        // }
        // else {
        //     std::cout << "Error: " << NFD_GetError() << std::endl;
        // }
    });
    MulFitPolicy buttonPolicy = {.type = MulFitType::Fix, .size = 200};
    button->setHorizontalFitPolicy(buttonPolicy);
    layout->addChild(button);
}

void MulFilePicker::setFilter(const std::string& filter_) {
    filter = filter_;
}

void MulFilePicker::addChangePathCallback(ChangePathCallbackType& outHandler, const std::function<void(std::filesystem::path)>& newCallback) {
    outHandler = std::make_shared<MulCallbackOwner<std::filesystem::path>>(newCallback);
    callbackCollection.addCallback(outHandler);
}