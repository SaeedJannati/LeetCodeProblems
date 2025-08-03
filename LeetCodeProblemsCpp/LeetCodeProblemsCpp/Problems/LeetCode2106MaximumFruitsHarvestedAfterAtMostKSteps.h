#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2106MaximumFruitsHarvestedAfterAtMostKSteps: BaseProblem
{
private:
  
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k);
public:
    void Run() override;
};
