#include "imgui.h"
#include "imgui_internal.h"
#include <iterator>
#include "mul_widget.h"
#include "mul_layout.h"


void MulLayout::draw() {
    updateChildrenList();
    for(const auto& child: childrens) {
        child->draw();
    }
}

void MulLayout::update(float dt) {
    for(const auto& child: childrens) {
        child->update(dt);
    }
}

void MulLayout::addChild(const std::shared_ptr<MulWidget>& newChild) {
    childrensForAdd.insert(newChild);
}

void MulLayout::removeChild(const std::shared_ptr<MulWidget>& newChild) {
    childrensForRemove.insert(newChild);
}

void MulLayout::removeChild(size_t index) {
    childrensForRemove.insert(childrens[index]);
}

void MulLayout::updateChildrenList() {
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