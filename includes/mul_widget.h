#pragma once
#include <memory>
#include <vector>

class MulWidget {
public:
    virtual void init();
    virtual void draw() const;
    virtual void update(float dt);

    void addChild(const std::shared_ptr<MulWidget>& newChild);

    virtual void onInit() = 0;
    virtual void onDraw() const = 0;
    virtual void onUpdate(float dt) = 0;
private:
    std::vector<std::shared_ptr<MulWidget>> childrens;
};