#include "widgets/mul_file_picker.h"
#include "mul_size_strategy.h"
#include "widgets/mul_button.h"
#include "widgets/mul_horizontal_layout.h"
#include "widgets/mul_label.h"
#include "mul_size_strategy.h"


void MulFilePicker::onInit() {
    auto layout = std::make_shared<MulHorizontalLayout>();
    setLayout(layout);

    auto newPathLabel = std::make_shared<MulLabel>();
    layout->addChild(newPathLabel);
    pathLabel = newPathLabel;

    auto newButton = std::make_shared<MulButton>();
    newButton->setText("Select");
    button = newButton;

    MulFitPolicy buttonPolicy = {.type = MulFitType::Fix, .size = 200};
    newButton->setHorizontalFitPolicy(buttonPolicy);
    layout->addChild(newButton);

    initFilePicker();
}
