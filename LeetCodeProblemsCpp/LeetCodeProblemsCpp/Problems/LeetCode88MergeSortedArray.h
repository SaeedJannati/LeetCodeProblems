#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode88MergeSortedArray: BaseProblem
{
public:
    void Run() override;
private:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
    void PrintVector(std::vector<int>& vector);
};
