#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3381MaximumSubarraySumWithLengthDivisibleByK: BaseProblem
{
public:
    long long maxSubarraySum(std::vector<int>& nums, int k);
    void Run() override;
};
