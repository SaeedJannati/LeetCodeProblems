#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode45JumpGameII: BaseProblem
{
public:
    void Run() override;
private:
    int jump(std::vector<int>& nums);
};  
