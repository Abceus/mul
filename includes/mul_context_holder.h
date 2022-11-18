#pragma once
#include "mul_context.h"

class MulContextHolder {
public:
    const MulContext* getContext() const;
protected:
    void setContext(MulContext* newContext);
    MulContext* m_context;
};
