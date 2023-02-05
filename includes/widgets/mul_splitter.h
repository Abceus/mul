#pragma once
#include "mul_widget.h"

#include <functional>
#include <memory>
#include <string>

class MulSplitter : public MulWidget {
public:
    MulSplitter() = default;
    void draw() override;

    void onUpdate(float dt) override {}
    void onInit() override {}
    void onDraw() override {}

    void onKeyPressed(const ImGuiInputEvent& event) override;

    void setFirstWidget(const std::shared_ptr<MulWidget>& newWidget);
    std::shared_ptr<MulWidget> getFirstWidget() const;

    void setSecondWidget(const std::shared_ptr<MulWidget>& newWidget);
    std::shared_ptr<MulWidget> getSecondWidget() const;

protected:
    std::shared_ptr<MulWidget> firstWidget;
    std::shared_ptr<MulWidget> secondWidget;
};