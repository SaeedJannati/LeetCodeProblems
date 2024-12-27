#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode11ContainerWithMostWater: BaseProblem
{
public:
    void Run() override;
private:
    int maxArea(std::vector<int>& height);
};
