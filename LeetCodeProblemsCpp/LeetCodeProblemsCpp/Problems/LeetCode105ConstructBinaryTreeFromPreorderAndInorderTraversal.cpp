#include "LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal.h"

#include <iostream>
#include <map>

void LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal::Run()
{
    std::vector<int> preorder{-1};
    std::vector<int> inorder{-1};
    auto root=buildTree(preorder, inorder);
    std::cout<<"Preorder: ";
    TreeNode::PrintPreOrder(root);
    std::cout<<'\n'<<"Inorder: ";
    TreeNode::PrintInOrder(root);
}

TreeNode* LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal::buildTree(
    std::vector<int>& preorder, std::vector<int>& inorder)
{
    std::map<int, int> inorderMap;
    int size = static_cast<int>(inorder.size());
    for (auto i = 0; i < size; i++)
        inorderMap[inorder[i]] = i;
    return GenerateSubTree(preorder, inorderMap, 0, 0, size - 1);
}

TreeNode* LeetCode105ConstructBinaryTreeFromPreorderAndInorderTraversal::GenerateSubTree(
    std::vector<int>& preorder, std::map<int, int>& inorderMap,
    int rootPreOrderIndex, int beginInOrderIndex, int endInOrderIndex)
{
    if (beginInOrderIndex > endInOrderIndex)
        return nullptr;
    auto root = new TreeNode(preorder[rootPreOrderIndex]);
    int rootInorderIndex = inorderMap[root->val];
    int leftTreeLength = rootInorderIndex - beginInOrderIndex;

    int leftTreeRootPreOrderIndex = rootPreOrderIndex + 1;

    int rightTreeRootPreOrderIndex = rootPreOrderIndex + leftTreeLength + 1;

    root->left = GenerateSubTree(preorder, inorderMap, leftTreeRootPreOrderIndex, beginInOrderIndex,
                                 rootInorderIndex - 1);
    root->right = GenerateSubTree(preorder, inorderMap, rightTreeRootPreOrderIndex, rootInorderIndex + 1,
                                  endInOrderIndex);
    return root;
}
