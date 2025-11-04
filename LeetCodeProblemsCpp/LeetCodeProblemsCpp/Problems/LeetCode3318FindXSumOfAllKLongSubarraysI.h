#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3318FindXSumOfAllKLongSubarraysI: BaseProblem
{
private:
    std::vector<int> findXSum(std::vector<int>& nums, int k, int x);
public:
    void Run() override;
};
