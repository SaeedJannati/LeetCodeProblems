#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode689MaximumSumof3NonOverlappingSubarrays: BaseProblem
{
public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k);
    void Run() override;
};
