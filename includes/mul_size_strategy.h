#pragma once

enum class MulFitType {
    Proportion,
    Fix
};

struct MulFitPolicy {
    MulFitType type = MulFitType::Proportion;
    float proportion = 1.0f;
    int size = 0;
};