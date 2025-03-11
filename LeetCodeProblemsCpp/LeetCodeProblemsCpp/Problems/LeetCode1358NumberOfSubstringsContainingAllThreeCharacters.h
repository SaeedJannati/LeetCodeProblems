#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode1358NumberOfSubstringsContainingAllThreeCharacters: BaseProblem
{
private:
    int numberOfSubstrings(std::string s);
public:
    void Run() override;
};
