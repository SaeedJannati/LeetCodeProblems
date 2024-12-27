#pragma once
#include <vector>

#include "BaseProblem.h"
#include "TreeNode.h"

class LeetCode108ConvertSortedArrayToBinarySearchTree: BaseProblem
{
public:
    void Run() override;
private:
    TreeNode* sortedArrayToBST(std::vector<int>& nums);
    TreeNode* GenerateSubTree(std::vector<int> nums, int rangeStart, int rangeEnd);
};
