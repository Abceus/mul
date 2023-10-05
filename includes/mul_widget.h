#pragma once
#include "imgui_internal.h"
#include "mul_node.h"
#include <memory>
#include <vector>
#include <set>
#include <optional>
#include "mul_size_strategy.h"
#include "mul_vec2.h"

class MulLayout;

class MulWidget : public MulNode {
public:
    void init();
    void draw() override;
    void update(float dt) override;

    virtual void onInit() = 0;
    virtual void onDraw() = 0;
    virtual void onUpdate(float dt) = 0;
    virtual void onKeyPressed(const ImGuiInputEvent& event);

    virtual void onMouseClickEvent(const ImGuiInputEvent& event);
    virtual void onMouseMoveEvent(const ImGuiInputEvent& event);
    virtual void onMouseScrollEvent(const ImGuiInputEvent& event);

    int getMinimumHeight() const;
    int getMaximumHeight() const;
    MulFitPolicy getVerticalFitPolicy() const;

    void setMinimumHeight(int value);
    void setMaximumHeight(int value);
    void setVeticalFitPolicy(const MulFitPolicy& value);

    int getMinimumWidth() const;
    int getMaximumWidth() const;
    MulFitPolicy getHorizontalFitPolicy() const;

    void setMinimumWidth(int value);
    void setMaximumWidth(int value);
    void setHorizontalFitPolicy(const MulFitPolicy& value);

    void setLayout(const std::shared_ptr<MulLayout>& newLayout);
    std::shared_ptr<MulLayout> getLayout() const;

    void setWidth(int value);
    void setHeight(int value);
    void setSize(const Vec2I& value);

    int getWidth() const;
    int getHeight() const;
    Vec2I getSize() const;

    virtual MulWidget* getWidgetByPosition(const Vec2I& position);

    static const int UNSET_MAXIMUM_VALUE = -1;
protected:
    int minimalHeight = 0;
    int maximumHeight = UNSET_MAXIMUM_VALUE;
    MulFitPolicy verticalFitPolicy;

    int minimalWidth = 0;
    int maximumWidth = UNSET_MAXIMUM_VALUE;
    MulFitPolicy horizontalFitPolicy;

    std::shared_ptr<MulLayout> layout;

    Vec2I size;
};