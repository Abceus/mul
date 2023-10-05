#include "widgets/mul_grid_layout.h"
#include <memory>
#include <numeric>

void MulGridLayout::draw() {
    {
        for(auto i = 0; i < childrens.size(); ++i) {
            auto column = i%columns;
            if(column==0) {
                // TableNextRow();
            }
            // TableSetColumnIndex(column);
            childrens[i]->draw();
        }
    }

    onDraw();
}

void MulGridLayout::setColumns(int value) {
    columns = value;
}

int MulGridLayout::getColumns() const {
    return columns;
}
