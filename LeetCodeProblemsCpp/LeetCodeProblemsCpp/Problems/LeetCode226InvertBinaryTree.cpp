#include "LeetCode226InvertBinaryTree.h"




void LeetCode226InvertBinaryTree::Run()
{
}

TreeNode* LeetCode226InvertBinaryTree::invertTree(TreeNode* root)
{
    if (root == nullptr)
        return nullptr;
    SwapLeftAndRight(root);
    return root;
}

void LeetCode226InvertBinaryTree::SwapLeftAndRight(TreeNode* node)
{
    auto temp = node->left;
    node->left = node->right;
    node->right = temp;
    if (node->left != nullptr)
        SwapLeftAndRight(node->left);
    if (node->right != nullptr)
        SwapLeftAndRight(node->right);
}
