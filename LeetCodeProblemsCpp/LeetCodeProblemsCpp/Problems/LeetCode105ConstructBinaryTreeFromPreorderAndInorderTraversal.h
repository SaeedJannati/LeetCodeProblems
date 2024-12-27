#pragma once
#include <map>
#include <vector>

#include "BaseProblem.h"
#include "TreeNode.h"

class LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal: BaseProblem
{
public:
    void Run() override;
private:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
    TreeNode* GenerateSubTree(std::vector<int>& preorder, std::map<int, int>& inorderMap, int rootPreOrderIndex,
                              int beginInOrderIndex, int endInOrderIndex);
};






