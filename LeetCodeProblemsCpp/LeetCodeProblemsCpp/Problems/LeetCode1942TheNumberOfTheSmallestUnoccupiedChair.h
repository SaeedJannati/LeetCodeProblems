#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode1942TheNumberOfTheSmallestUnoccupiedChair: BaseProblem
{
private:
    int smallestChair(std::vector<std::vector<int>>& times, int targetFriend);
public:
    void Run() override;
};
