#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode54SpiralMatrix: BaseProblem
{
public:
    void Run() override;
private:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
    void PrintVector(std::vector<int>& vector);
};
