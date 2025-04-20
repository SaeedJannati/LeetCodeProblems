#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode781RabbitsInForest: BaseProblem
{
private:
    int numRabbits(std::vector<int>& answers);
public:
    void Run() override;
    
};
