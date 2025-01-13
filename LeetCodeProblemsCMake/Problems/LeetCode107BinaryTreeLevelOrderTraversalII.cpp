//
// Created by saeed on 1/13/25.
//

#include "LeetCode107BinaryTreeLevelOrderTraversalII.h"

#include <algorithm>
#include <queue>

#include "../Auxilary/TreeNode.h"

std::vector<std::vector<int>> LeetCode107BinaryTreeLevelOrderTraversalII::levelOrderBottom(TreeNode *root) {
    if (root == nullptr)
        return {};
    std::queue<TreeNode*> currentLayer;
    std::queue<TreeNode*> nextLayer;
    currentLayer.push(root);
    std::vector<std::vector<int>> result;
    while (!currentLayer.empty()) {
        std::vector<int> layerValues;
        layerValues.reserve(currentLayer.size());
        while(!currentLayer.empty()) {
            TreeNode* node = currentLayer.front();
            currentLayer.pop();
            layerValues.push_back(node->val);
            if(node->left != nullptr) {
                nextLayer.push(node->left);
            }
            if (node->right != nullptr) {
                nextLayer.push(node->right);
            }
        }
        result.push_back(layerValues);
        while(!nextLayer.empty()) {
            currentLayer.push(nextLayer.front());
            nextLayer.pop();
        }
    }
    std::ranges::reverse(result);
    return result;
}
