#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2210CountHillsAndValleysInAnArray: BaseProblem
{
private:
    int countHillValley(std::vector<int>& nums);
public:
    void Run() override;
    
};
