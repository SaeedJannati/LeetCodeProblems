#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode1765MapOfHighestPeak: BaseProblem
{
private:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater);
public:
    void Run() override;
};
