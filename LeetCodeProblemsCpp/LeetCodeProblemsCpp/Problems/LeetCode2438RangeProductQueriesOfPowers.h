#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2438RangeProductQueriesOfPowers: BaseProblem
{
private:
    std::vector<int> productQueries(int n, std::vector<std::vector<int>>& queries); 
public:
    void Run() override;
};
