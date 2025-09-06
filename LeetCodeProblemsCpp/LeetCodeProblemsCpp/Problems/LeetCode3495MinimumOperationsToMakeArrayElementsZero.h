#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3495MinimumOperationsToMakeArrayElementsZero: BaseProblem
{
private:
    long long minOperations(std::vector<std::vector<int>>& queries);
public:
    void Run() override;
    
};
