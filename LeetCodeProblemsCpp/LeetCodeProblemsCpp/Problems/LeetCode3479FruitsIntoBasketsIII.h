#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3479FruitsIntoBasketsIII: BaseProblem
{
private:
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets);
    public:
    void Run() override;
};
