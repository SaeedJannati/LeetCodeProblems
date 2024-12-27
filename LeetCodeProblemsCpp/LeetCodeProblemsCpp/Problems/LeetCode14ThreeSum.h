#pragma once
#include <string>
#include <vector>

#include "BaseProblem.h"
#include <sstream>
class LeetCode14ThreeSum : BaseProblem
{
public:
    void Run() override;
private:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    void SortVector(std::vector<int>& vector);
    void PrintTwoDimensionalArray( std::vector<std::vector<int>>& input);
    
};
