#include <mul_widget.h>

void MulWidget::init() {
    onInit();
}

void MulWidget::draw() {
    for(const auto& child: childrens) {
        child->draw();
    }
    onDraw();
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
