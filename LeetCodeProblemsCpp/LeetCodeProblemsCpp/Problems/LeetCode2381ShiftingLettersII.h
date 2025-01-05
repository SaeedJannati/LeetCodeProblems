#pragma once
#include <string>
#include <vector>

#include "BaseProblem.h"

class LeetCode2381ShiftingLettersII: BaseProblem
{
private:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts);
public:
 void Run() override;
};
