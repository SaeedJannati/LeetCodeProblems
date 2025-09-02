#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3025FindTheNumberOfWaysToPlacePeopleI: BaseProblem
{
private:
    int numberOfPairs(std::vector<std::vector<int>>& points);
    public:
    void Run() override;
};
