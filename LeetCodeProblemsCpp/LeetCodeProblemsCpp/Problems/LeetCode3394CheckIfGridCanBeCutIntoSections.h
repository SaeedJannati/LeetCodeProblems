#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode3394CheckIfGridCanBeCutIntoSections: BaseProblem
{
private:
    bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles);
public:
void Run() override;

    
};
