#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3201FindTheMaximumLengthOfValidSubsequenceI : BaseProblem
{
private:
    int maximumLength(std::vector<int>& nums);
public:
    void Run() override;
};
