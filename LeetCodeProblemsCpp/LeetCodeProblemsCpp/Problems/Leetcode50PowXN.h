#pragma once
#include "BaseProblem.h"

class Leetcode50PowXN:BaseProblem
{
public:
    void Run() override;
private:
    double myPow(double x, int n);
};
