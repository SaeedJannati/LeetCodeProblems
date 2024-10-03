#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode198HouseRobber : BaseProblem
{
public:
    void Run() override;

private:
    int rob(std::vector<int>& nums);
};
