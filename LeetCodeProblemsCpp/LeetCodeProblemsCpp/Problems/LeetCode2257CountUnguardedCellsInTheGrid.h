#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2257CountUnguardedCellsInTheGrid: BaseProblem
{
public:
    int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls);
    void Run() override;
};
