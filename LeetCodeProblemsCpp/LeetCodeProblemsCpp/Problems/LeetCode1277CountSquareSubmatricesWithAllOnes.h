#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode1277CountSquareSubmatricesWithAllOnes: BaseProblem
{
private:
    int countSquares(std::vector<std::vector<int>>& matrix);
public:
    void Run() override;
    
};
