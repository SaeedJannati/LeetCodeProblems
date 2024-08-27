#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode48RotateImage:BaseProblem
{
public:
    void Run() override;
private:
    void rotate(std::vector<std::vector<int>>& matrix);
    void PrintMatrix(std::vector<std::vector<int>>& matrix);
};
