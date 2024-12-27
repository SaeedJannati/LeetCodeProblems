#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode10RegularExpressionMatching: BaseProblem
{
public:
    void Run() override;

private:
    bool isMatch(std::string s, std::string p);
};
