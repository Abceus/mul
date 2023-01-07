#pragma once
#include <memory>
#include <vector>

enum class FitPolicy {
    Proportion,
    Fix
};

class MulWidget {
public:
    virtual void init();
    virtual void draw();
    virtual void update(float dt);

    void addChild(const std::shared_ptr<MulWidget>& newChild);

    virtual void onInit() = 0;
    virtual void onDraw() = 0;
    virtual void onUpdate(float dt) = 0;

    float getFillHorizontalSpace() const;
    void setFillHorizontalSpace(float value);

    float getWidth() const;
    void setWidth(float  value);

    FitPolicy getFitPolicy() const;
    void setFitPolicy(FitPolicy value);
protected:
    std::vector<std::shared_ptr<MulWidget>> childrens;

    float fillHorizontalSpace = 1.0f;
    float width = 0.0f;
    FitPolicy fitPolicy = FitPolicy::Proportion;
};