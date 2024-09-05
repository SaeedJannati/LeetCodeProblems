#pragma once
#include <map>
#include <vector>

#include "BaseProblem.h"
#include "TreeNode.h"

class LeetCode106ConstructBinaryTreeFromInorderAndPostorderTraversal:BaseProblem
{
public:
    void Run() override;
    private:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);
    TreeNode* GenerateSubTree(std::map<int, int>& inorderMap, std::vector<int>& postorder, int rootPostorderIndex,
                              int beginInorderIndex, int endInorderIndex);
};
