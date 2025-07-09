//
// Created by saeed on 6/30/25.
//

#include "LeetCode429NaryTreeLevelOrderTraversal.h"

#include <queue>
using namespace std;
 vector< vector<int>> LeetCode429NaryTreeLevelOrderTraversal::levelOrder(Node *root) {
    vector<vector<int>> result{};
     if (root == nullptr)
         return result;
     queue<Node *> currentLayer{};
     queue<Node *> nextLayer{};
     currentLayer.push(root);
     while (!currentLayer.empty()) {
         vector<int> level{};
         while (!currentLayer.empty()) {
             auto node = currentLayer.front();
             currentLayer.pop();
             level.push_back(node->val);
             for (auto child : node->children) {
                 nextLayer.push(child);
             }
         }
         result.push_back(level);
         while (!nextLayer.empty()) {
             currentLayer.push(nextLayer.front());
             nextLayer.pop();
         }
     }
     return result;
}
