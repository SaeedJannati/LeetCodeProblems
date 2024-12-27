#pragma once
#include <string>
#include <vector>

#include "BaseProblem.h"

class LeetCode8StringToInteger: BaseProblem
{
public:
    void Run() override;
private:
    int myAtoi(std::string s);
    int ConvertExtractedNumbers(std::vector<unsigned char>& extractedNumbers,bool isPositive);
    void ReverseFormatedNumber(std::vector<unsigned char>& formatedNumber);
    bool IsGreaterThan(std::vector<unsigned char> first, std::vector<unsigned char> second);
    std::vector<unsigned char> GetFormatedNumber(int x);
};
