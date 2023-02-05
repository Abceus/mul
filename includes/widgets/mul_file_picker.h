#pragma once
#include "widgets/mul_file_picker_base.h"


class MulFilePicker : public MulFilePickerBase {
public:
    MulFilePicker() = default;
    void onDraw() override {} ;

    void onUpdate(float dt) override {}
    void onInit() override;
};