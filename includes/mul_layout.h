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

protected:
    std::vector<std::shared_ptr<MulWidget>> childrens;
    std::set<std::shared_ptr<MulWidget>> childrensForAdd;
    std::set<std::shared_ptr<MulWidget>> childrensForRemove;

    void updateChildrenList();
};