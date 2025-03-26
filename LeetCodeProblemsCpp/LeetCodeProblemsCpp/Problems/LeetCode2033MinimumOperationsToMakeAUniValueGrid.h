#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2033MinimumOperationsToMakeAUniValueGrid: BaseProblem
{
private:
    int minOperations(std::vector<std::vector<int>>& grid, int x);
public:
    void Run() override;
};
