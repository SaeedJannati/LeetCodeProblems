#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode2116CheckIfAParenthesesStringCanBeValid: BaseProblem
{
private:
    bool canBeValid(std::string s, std::string locked);
    public:
    void Run() override;
};
