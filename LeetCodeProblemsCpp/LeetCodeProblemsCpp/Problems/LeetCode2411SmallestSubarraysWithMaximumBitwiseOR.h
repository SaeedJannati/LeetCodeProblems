#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2411SmallestSubarraysWithMaximumBitwiseOR: BaseProblem
{
private:
    std::vector<int> smallestSubarrays(std::vector<int>& nums);
public:
    void Run() override;
};
