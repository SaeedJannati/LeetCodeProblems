#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2560HouseRobberIV: BaseProblem
{
private:
    int minCapability(std::vector<int>& nums, int k);
public:
    void Run() override;
};
