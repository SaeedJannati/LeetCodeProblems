#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger: BaseProblem
{
private:
    int maximumCount(std::vector<int>& nums);
public:
    void Run() override;
    
};
