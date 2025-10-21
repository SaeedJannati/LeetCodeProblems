#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3346MaximumFrequencyOfAnElementAfterPerformingOperationsI: BaseProblem
{
private:
    int maxFrequency(std::vector<int>& nums, int k, int numOperations);
    public:
    void Run() override;
};
