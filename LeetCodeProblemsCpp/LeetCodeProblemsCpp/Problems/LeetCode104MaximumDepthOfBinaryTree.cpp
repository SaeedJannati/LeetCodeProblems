#include "LeetCode104MaximumDepthOfBinaryTree.h"

#include <iostream>
#include <map>
#include <vector>

void LeetCode104MaximumDepthOfBinaryTree::Run()
{
    auto three = TreeNode(3);
    auto nine = TreeNode(9);
    auto twenty = TreeNode(20);
    auto fifteen = TreeNode(15);
    auto seven = TreeNode(7);
    three.left = &nine;
    three.right = &twenty;
    twenty.left = &fifteen;
    twenty.right = &seven;
    std::cout << maxDepth(&three);
}

int LeetCode104MaximumDepthOfBinaryTree::maxDepth(TreeNode* root)
{
    if(root==nullptr)
        return 0;
    PreOrder(root, 1);
    return currentMaxDepth;
}

void LeetCode104MaximumDepthOfBinaryTree::PreOrder(TreeNode* node, int depth)
{
    if (node == nullptr)
        return;
    if (currentMaxDepth < depth)
        currentMaxDepth = depth;
    depth++;
    PreOrder(node->left, depth);
    PreOrder(node->right, depth);
}
