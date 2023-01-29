#include "imgui.h"
#include "imgui_internal.h"
#include <iterator>
#include <mul_widget.h>
#include "mul_layout.h"

void MulWidget::init() {
}

void MulWidget::draw() {
    if(layout) {
        layout->draw();
    }
    onDraw();
}

void MulWidget::update(float dt) {
    if(layout) {
        layout->update(dt);
    }
    onUpdate(dt);
}

void MulWidget::onKeyPressed(const ImGuiInputEvent& event) {
}

int MulWidget::getMinimumHeight() const {
    return minimalHeight;
}

int MulWidget::getMaximumHeight() const {
    return maximumHeight;
}

MulFitPolicy MulWidget::getVerticalFitPolicy() const {
    return verticalFitPolicy;
}

void MulWidget::setMinimumHeight(int value) {
    minimalWidth = value;
}

void MulWidget::setMaximumHeight(int value) {
    maximumWidth = value;
}

void MulWidget::setVeticalFitPolicy(const MulFitPolicy& value) {
    verticalFitPolicy = value;
}

int MulWidget::getMinimumWidth() const {
    return minimalWidth;
}

int MulWidget::getMaximumWidth() const {
    return maximumWidth;
}

MulFitPolicy MulWidget::getHorizontalFitPolicy() const {
    return horizontalFitPolicy;
}

void MulWidget::setMinimumWidth(int value) {
    minimalWidth = value;
}

void MulWidget::setMaximumWidth(int value) {
    maximumWidth = value;
}

void MulWidget::setHorizontalFitPolicy(const MulFitPolicy& value) {
    horizontalFitPolicy = value;
}

void MulWidget::setLayout(const std::shared_ptr<MulLayout>& newLayout) {
    layout = newLayout;
}

std::shared_ptr<MulLayout> MulWidget::getLayout() const {
    return layout;
}

void MulWidget::setWidth(int value) {
    size.setX(value);
}

void MulWidget::setHeight(int value) {
    size.setY(value);
}

void MulWidget::setSize(const Vec2I& value) {
    size = value;
}

int MulWidget::getWidth() const {
    return size.getX();
}

int MulWidget::getHeight() const {
    return size.getY();
}

Vec2I MulWidget::getSize() const {
    return size;
}
