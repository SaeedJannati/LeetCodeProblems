//
// Created by saeed on 6/28/25.
//

#include "LeetCode513FindBottomLeftTreeValue.h"

#include <queue>
#include <utility>

#include "../Auxilary/TreeNode.h"
using namespace std;
int LeetCode513FindBottomLeftTreeValue::findBottomLeftValue(TreeNode *root) {
    queue<TreeNode*> currentLayer{};
    queue<TreeNode*> nextLayer{};
    currentLayer.push(root);
    int result{};
    while (!currentLayer.empty()) {
        result=currentLayer.front()->val;
        while (!currentLayer.empty()) {
            auto node=currentLayer.front();
            currentLayer.pop();
            if (node->left!=nullptr) {
                nextLayer.push(node->left);
            }
            if (node->right!=nullptr) {
                nextLayer.push(node->right);
            }
        }
        while (!nextLayer.empty()) {
            currentLayer.push(nextLayer.front());
            nextLayer.pop();
        }
    }
    return result;
}
