#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode87ScrambleString: BaseProblem
{
private:
    bool isScramble(std::string s1, std::string s2);
public:
    void Run() override;
};
