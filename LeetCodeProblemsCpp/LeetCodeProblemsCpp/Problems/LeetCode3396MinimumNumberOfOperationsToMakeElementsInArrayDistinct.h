#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3396MinimumNumberOfOperationsToMakeElementsInArrayDistinct: BaseProblem
{
private:
    int minimumOperations(std::vector<int>& nums);
public:
    void Run() override;
};
