#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode907SumOfSubarrayMinimums: BaseProblem
{
private:
    int sumSubarrayMins(std::vector<int>& arr);
    public:
    void Run() override;
    
};
