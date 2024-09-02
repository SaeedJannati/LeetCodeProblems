#pragma once
#include "BaseProblem.h"

struct TreeNode;

class LeetCode226InvertBinaryTree : BaseProblem
{
public:
    void Run() override;

private:
    TreeNode* invertTree(TreeNode* root);
    void SwapLeftAndRight(TreeNode* node);
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};
