#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode215FindKthElement: BaseProblem
{
public:
    void Run() override;
private:
    int findKthLargest(std::vector<int>& nums, int k);
};
