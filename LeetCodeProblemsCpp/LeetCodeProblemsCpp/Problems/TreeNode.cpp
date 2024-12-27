#include "TreeNode.h"

#include <iostream>

void TreeNode::PrintInOrder(TreeNode* root)
{
    if(root==nullptr)
        return;
    PrintInOrder(root->left);
    std::cout<<root->val<<" ";
    PrintInOrder(root->right);
}
void TreeNode::PrintPreOrder(TreeNode* root)
{
    if(root==nullptr)
        return;
    std::cout<<root->val<<" ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
}
void TreeNode::PrintPostOrder(TreeNode* root)
{
    if(root==nullptr)
        return;
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    std::cout<<root->val<<" ";
}


