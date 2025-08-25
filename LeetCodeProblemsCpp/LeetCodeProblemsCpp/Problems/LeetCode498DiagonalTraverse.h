#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode498DiagonalTraverse: BaseProblem
{
private:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat);
public:
    void Run() override;
    
};
