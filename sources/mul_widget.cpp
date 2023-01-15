#include "imgui.h"
#include "imgui_internal.h"
#include <iterator>
#include <mul_widget.h>

void MulWidget::init() {
}

void MulWidget::draw() {
    ImGui::PushItemWidth(width);
    onDraw();
    ImGui::PopItemWidth();
    updateChildrenList();
    for(const auto& child: childrens) {
        child->draw();
    }
}

void MulWidget::update(float dt) {
    for(const auto& child: childrens) {
        child->update(dt);
    }
    onUpdate(dt);
}

void MulWidget::addChild(const std::shared_ptr<MulWidget>& newChild) {
    childrensForAdd.insert(newChild);
}

void MulWidget::removeChild(const std::shared_ptr<MulWidget>& newChild) {
    childrensForRemove.insert(newChild);
}

void MulWidget::removeChild(size_t index) {
    childrensForRemove.insert(childrens[index]);
}

void MulWidget::onKeyPressed(const ImGuiInputEvent& event) {
    for(const auto& child: childrens) {
        child->onKeyPressed(event);
    }
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

void MulWidget::updateChildrenList() {
    childrens.insert(std::end(childrens), std::begin(childrensForAdd), std::end(childrensForAdd));
    childrensForAdd.clear();

    // TODO
    for(const auto& childForRemove: childrensForRemove) {
        auto found = std::find(std::begin(childrens), std::end(childrens), childForRemove);
        if(found != std::end(childrens)) {
            childrens.erase(found);
        }
    }
    childrensForRemove.clear();
}