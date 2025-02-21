//
// Created by saeed on 2/21/25.
//

#include "LeetCode1261FindElementsInAContaminatedBinaryTree.h"

#include <unordered_set>

#include "../Auxilary/TreeNode.h"
struct TreeNode;

class FindElements {
public:
    std::unordered_set<int> _treeValues{};

    FindElements(TreeNode *root) {
        root->val = 0;
        _treeValues.insert(root->val);
        if (root->left != nullptr)
            Dfs(root->left, 0, true);
        if (root->right != nullptr)
            Dfs(root->right, 0, false);
    }

    bool find(int target) {
        return _treeValues.contains(target);
    }

    void Dfs(TreeNode *node, int parentValue, bool isLeftNode) {
        node->val = 2 * parentValue;
        node->val += isLeftNode ? 1 : 2;
        _treeValues.insert(node->val);
        if (node->left != nullptr)
            Dfs(node->left, node->val, true);
        if (node->right != nullptr)
            Dfs(node->right, node->val, false);
    }
};
