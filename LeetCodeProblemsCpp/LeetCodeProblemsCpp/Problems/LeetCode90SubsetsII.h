#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode90SubsetsII: BaseProblem
{
private:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);
public:
void Run() override;    
};
