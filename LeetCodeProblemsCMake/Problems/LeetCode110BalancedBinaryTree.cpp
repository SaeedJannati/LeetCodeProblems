//
// Created by saeed on 2/8/26.
//

#include "LeetCode110BalancedBinaryTree.h"

#include <algorithm>

#include "../Auxilary/TreeNode.h"
using namespace std;
int calcHeight(TreeNode *node, bool *notBalanced) {
    if (!notBalanced) {
        return 0;
    }
    if (node == nullptr) {
        return 0;
    }
    node->val = calcHeight(node->left, notBalanced);
    int right = calcHeight(node->right, notBalanced);
    if (node->val - right > 1 || node->val - right < -1) {
        *notBalanced = true;
        return 0;
    }
    node->val=max(node->val, right)+1;
    return node->val;
}

bool LeetCode110BalancedBinaryTree::isBalanced(TreeNode *root) {
    bool notBalanced = false;
    calcHeight(root, &notBalanced);
    return !notBalanced;
}
