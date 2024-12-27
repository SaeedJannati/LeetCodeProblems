#pragma once
#include "BaseProblem.h"

struct TreeNode;

class LeetCode150SameTree : BaseProblem
{
public:
    void Run() override;

private:
    bool isSameTree(TreeNode* p, TreeNode* q);
    bool CheckIfSame(TreeNode* pNode, TreeNode* qNode);
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
