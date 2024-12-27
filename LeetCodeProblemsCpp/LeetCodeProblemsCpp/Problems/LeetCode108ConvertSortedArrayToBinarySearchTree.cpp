#include "LeetCode108ConvertSortedArrayToBinarySearchTree.h"

void LeetCode108ConvertSortedArrayToBinarySearchTree::Run()
{
    std::vector<int> input = {-10,-3,0,5,9};
    const auto root = sortedArrayToBST(input);
    TreeNode::PrintInOrder(root);
}

TreeNode* LeetCode108ConvertSortedArrayToBinarySearchTree::sortedArrayToBST(std::vector<int>& nums)
{
    int size = static_cast<int>(nums.size());
    if (size == 0)
        return nullptr;
    if (size == 1)
        return new TreeNode(nums[0]);

    TreeNode* root = GenerateSubTree(nums, 0, size - 1);
    return root;
}

TreeNode* LeetCode108ConvertSortedArrayToBinarySearchTree::GenerateSubTree(
    std::vector<int> nums, int rangeStart, int rangeEnd)
{
    if (rangeEnd < rangeStart)
        return nullptr;
    if (rangeEnd == rangeStart)
        return new TreeNode(nums[rangeStart]);
    int rootIndex = (rangeStart + rangeEnd) / 2 ;
    TreeNode* root = new TreeNode(nums[rootIndex]);
    root->left = GenerateSubTree(nums, rangeStart, rootIndex - 1);
    root->right = GenerateSubTree(nums, rootIndex + 1, rangeEnd);
    return root;
}
