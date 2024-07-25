#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode7ReverseInteger:BaseProblem
{
public:
    void Run() override;
private:
    int reverse(int x);
    void ReverseFormatedNumber(std::vector<unsigned char>& formatedNumber);
    std::vector<unsigned char> GetFormatedNumber(int x);
    bool IsGreaterThan(std::vector<unsigned char> first, std::vector<unsigned char> second);
};
