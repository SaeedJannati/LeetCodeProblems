#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode73SetMatrixZeroes: BaseProblem
{
public:
    void Run() override;
private:
    void setZeroes(std::vector<std::vector<int>>& matrix);
    void PrintMatrix(const std::vector<std::vector<int>>& matrix);
};
