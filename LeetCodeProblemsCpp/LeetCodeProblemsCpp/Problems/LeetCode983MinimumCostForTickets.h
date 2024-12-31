#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode983MinimumCostForTickets: BaseProblem
{
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs);
    void Run() override;
};
