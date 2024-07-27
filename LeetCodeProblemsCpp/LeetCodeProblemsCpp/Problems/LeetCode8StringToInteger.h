#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode8StringToInteger: BaseProblem
{
public:
    void Run() override;
private:
    int myAtoi(std::string s);
};
