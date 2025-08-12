#pragma once
#include "BaseProblem.h"

class LeetCode2787WaysToExpressAnIntegerAsSumOfPowers: BaseProblem
{
private:
    int numberOfWays(int n, int x);
    public:
    void Run() override;
};
