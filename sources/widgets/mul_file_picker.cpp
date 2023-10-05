#include "widgets/mul_file_picker.h"
#include "mul_widget.h"
#include "widgets/mul_button.h"
#include "widgets/mul_horizontal_layout.h"
#include "widgets/mul_label.h"
#include <filesystem>
#include <memory>


void MulFilePicker::onInit() {
    auto layout = std::make_shared<MulHorizontalLayout>();
    addChild(layout);

    pathLabel = std::make_shared<MulLabel>();
    layout->addChild(pathLabel);

    button = std::make_shared<MulButton>();
    button->setText("Select");
    buttonCallback = button->addClickCallback([this](){
        if ( false ) { // file selected
            std::string outPath; // selected path
            pathLabel->setText(outPath);
            callbackCollection.call(outPath);
        }
        // else if ( result == NFD_CANCEL ) {
        //     std::cout << "User pressed cancel." << std::endl;
        // }
        // else {
        //     std::cout << "Error: " << NFD_GetError() << std::endl;
        // }
    });
    button->setWidth(200.0f);
    button->setFitPolicy(FitPolicy::Fix);
    layout->addChild(button);
}


std::shared_ptr<MulCallbackOwner<std::filesystem::path>> MulFilePicker::addChangePathCallback(const std::function<void(std::filesystem::path)>& newCallback) {
    auto result = std::make_shared<MulCallbackOwner<std::filesystem::path>>(newCallback);
    callbackCollection.addCallback(result);
    return result;
}