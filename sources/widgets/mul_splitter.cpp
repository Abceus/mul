#include "widgets/mul_splitter.h"
#include "mul_widget.h"
#include <memory>

void MulSplitter::draw() {
    {
        if(firstWidget)
        {
            // TableNextColumn();
            firstWidget->draw();
        }
        if(secondWidget)
        {
            // TableNextColumn();
            secondWidget->draw();
        }
    }

    onDraw();
}

void MulSplitter::setFirstWidget(const std::shared_ptr<MulWidget>& newWidget) {
    firstWidget = newWidget;
}

std::shared_ptr<MulWidget> MulSplitter::getFirstWidget() const {
    return firstWidget;
}

void MulSplitter::setSecondWidget(const std::shared_ptr<MulWidget>& newWidget) {
    secondWidget = newWidget;
}

std::shared_ptr<MulWidget> MulSplitter::getSecondWidget() const {
    return secondWidget;
}
