#pragma once
#include "BaseProblem.h"

class LeetCode9PalindromeNumber: BaseProblem
{
public:
    void Run() override;
private:
    bool isPalindrome(int x);
};
