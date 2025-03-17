//
// Created by saeed on 3/17/25.
//

#include "LeetCode99RecoverBinarySearchTree.h"

#include <algorithm>
#include <unordered_set>
#include <vector>
#include <bits/ranges_algo.h>

#include "../Auxilary/TreeNode.h"
using namespace std;

void ExtractInOrderTraversal(TreeNode *node, vector<TreeNode *> &inOrderTraversal,vector<int>& nodeValues) {
    if (node->left != nullptr)
        ExtractInOrderTraversal(node->left, inOrderTraversal,nodeValues);
    inOrderTraversal.push_back(node);
    nodeValues.push_back(node->val);
    if (node->right != nullptr)
        ExtractInOrderTraversal(node->right, inOrderTraversal,nodeValues);
}

void LeetCode99RecoverBinarySearchTree::recoverTree(TreeNode *root) {
    if (root == nullptr)
        return;
    vector<TreeNode *> inOrderTraversal{};
    vector<int> nodeValues{};
    ExtractInOrderTraversal(root, inOrderTraversal,nodeValues);
    ranges::sort(nodeValues);
    for (int i = 0, e = static_cast<int>(inOrderTraversal.size()); i < e; i++) {
       if (nodeValues[i]!=inOrderTraversal[i]->val) {
           inOrderTraversal[i]->val = nodeValues[i];
       }
    }
}
