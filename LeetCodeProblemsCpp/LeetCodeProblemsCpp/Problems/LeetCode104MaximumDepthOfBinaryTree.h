#pragma once
#include "BaseProblem.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class LeetCode104MaximumDepthOfBinaryTree: BaseProblem
{
public:
    void Run() override;
private:
    int currentMaxDepth=0;
    int maxDepth(TreeNode* root);
    void PreOrder(TreeNode* node, int depth);
};





