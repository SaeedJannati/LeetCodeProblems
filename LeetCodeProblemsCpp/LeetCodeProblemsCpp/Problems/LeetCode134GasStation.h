#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode134GasStation:BaseProblem
{
public:
    void Run() override;
private:
    
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost);
};
