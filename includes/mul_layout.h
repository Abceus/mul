#pragma once
#include "mul_node.h"
#include <vector>
#include <memory>
#include <set>

class MulWidget;

class MulLayout : public MulNode {
public:
    void init() {}
    void draw() override;
    void update(float dt) override;

    void addChild(const std::shared_ptr<MulWidget>& newChild);
    void removeChild(const std::shared_ptr<MulWidget>& newChild);
    void removeChild(size_t index);

    virtual void onKeyPressed(const ImGuiInputEvent& event);
protected:
    std::vector<std::shared_ptr<MulWidget>> childrens;
    std::vector<std::shared_ptr<MulWidget>> childrensForAdd;
    std::vector<std::shared_ptr<MulWidget>> childrensForRemove;

    void updateChildrenList();
};