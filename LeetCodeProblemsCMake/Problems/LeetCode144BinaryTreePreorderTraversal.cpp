//
// Created by saeed on 7/1/25.
//

#include "LeetCode144BinaryTreePreorderTraversal.h"

#include "../Auxilary/TreeNode.h"
using namespace std;
void POT(TreeNode* node,vector<int>& result) {
    if (node==nullptr) {
        return;
    }
    result.push_back(node->val);
    if (node->left!=nullptr) {
     POT(node->left,result);
    }
    if (node->right!=nullptr)
        POT(node->right,result);
}
vector<int> LeetCode144BinaryTreePreorderTraversal::preorderTraversal(TreeNode *root) {
    vector<int> result{};
    POT(root,result);
    return result;
}
