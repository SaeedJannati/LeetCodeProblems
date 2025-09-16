#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode2197ReplaceNonCoprimeNumbersInArray: BaseProblem
{
private:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums);
    public:
    void Run() override;
    
};
