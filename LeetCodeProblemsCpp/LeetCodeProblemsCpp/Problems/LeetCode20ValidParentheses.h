#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode20ValidParentheses:BaseProblem
{
public:
    void Run() override;
private:
    bool isValid(std::string s);
    
};
