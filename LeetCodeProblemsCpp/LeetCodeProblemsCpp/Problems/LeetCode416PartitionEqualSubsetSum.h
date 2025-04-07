#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode416PartitionEqualSubsetSum: BaseProblem
{
private:
    bool canPartition(std::vector<int>& nums);
public:
    void Run() override;
};
