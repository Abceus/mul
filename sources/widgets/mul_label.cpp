#include "widgets/mul_label.h"


void MulLabel::onDraw() {
    //Text("%s", text.c_str());
}

void MulLabel::setText(const std::string& _text) {
    text = _text;
}

std::string MulLabel::getText() const {
    return text;
}