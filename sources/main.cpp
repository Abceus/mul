#include <iostream>
#include <memory>

#include <mul_context.h>
#include <mul_window.h>

int main() {
    auto& context = MulContext::getCurrentContext();
    context.init();

    auto window = new MulWindow();
    window->init("Window title", {1000, 1000});
    window->show();

    auto window2 = new MulWindow();
    window2->init("Window title 2", {100, 100});
    window2->show();

    context.run();

    delete window;

    return 0;
}