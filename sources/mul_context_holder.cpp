#include "mul_context_holder.h"

const MulContext* MulContextHolder::getContext() const {
    return m_context;
}

void MulContextHolder::setContext(MulContext* newContext) {
    m_context = newContext;
}