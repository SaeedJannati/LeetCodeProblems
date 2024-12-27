#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode135Candy:BaseProblem
{
public:
    void Run() override;
private:
    int candy(std::vector<int>& ratings);
};
