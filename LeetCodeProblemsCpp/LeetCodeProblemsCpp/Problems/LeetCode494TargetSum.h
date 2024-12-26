#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode494TargetSum: BaseProblem
{
public:
    int findTargetSumWays(std::vector<int>& nums, int target) ;
    int Recurse(std::vector<int>& nums, int currentTarget, int index, std::vector<std::vector<int>>& dp, int minValue, int sum);
    void Run() override;
};
