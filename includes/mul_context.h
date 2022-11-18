#pragma once
#include "mul_window.h"

#include <set>
#include <memory>

class MulContext {
    friend MulWindow;
public:
    MulContext(const MulContext& other) = delete;
    void init();
    void run();


    MulContext& operator=(const MulContext& other) = delete;
    
    static MulContext& getCurrentContext();
private:
    void registerWindow(MulWindow* window);
    void unregisterWindow(MulWindow* window);

    MulContext() = default;
    std::set<MulWindow*> m_windows;
};
