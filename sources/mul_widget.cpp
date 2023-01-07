#include "imgui.h"
#include <mul_widget.h>

void MulWidget::init() {
    onInit();
}

void MulWidget::draw() {
    for(const auto& child: childrens) {
        child->draw();
    }
    ImGui::PushItemWidth(width);
    onDraw();
    ImGui::PopItemWidth();
}

void MulWidget::update(float dt) {
    for(const auto& child: childrens) {
        child->update(dt);
    }
    onUpdate(dt);
}

void MulWidget::addChild(const std::shared_ptr<MulWidget>& newChild) {
    childrens.emplace_back(newChild);
}

float MulWidget::getFillHorizontalSpace() const {
    return fillHorizontalSpace;
}

void MulWidget::setFillHorizontalSpace(float value) {
    fillHorizontalSpace = value;
}

float MulWidget::getWidth() const {
    return width;
}

void MulWidget::setWidth(float value) {
    width = value;
}

FitPolicy MulWidget::getFitPolicy() const {
    return fitPolicy;
}

void MulWidget::setFitPolicy(FitPolicy value) {
    fitPolicy = value;
}
