#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2017GridGame: BaseProblem
{
private:
    long long gridGame(std::vector<std::vector<int>>& grid);
public:
    void Run() override;
};
