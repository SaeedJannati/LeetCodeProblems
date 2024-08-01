#pragma once
#include <string>
#include <vector>

#include "BaseProblem.h"

class Leetcode12IntegerToRoman:BaseProblem
{
public:
    void Run() override;
private:
    std::string intToRoman(int num);
    int GetClosestLesserNum(int num,std::vector<int>& nums,int numsSize );
};
