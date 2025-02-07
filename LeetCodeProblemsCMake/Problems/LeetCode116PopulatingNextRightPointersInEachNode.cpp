//
// Created by saeed on 2/7/25.
//

#include "LeetCode116PopulatingNextRightPointersInEachNode.h"

#include <queue>
#pragma region Recursion
void Dfs(Node *parent, Node *node, bool isLeftNode) {
    if (isLeftNode)
        node->next = parent->right;
    else {
        if (parent->next == nullptr)
            node->next = nullptr;
        else
            node->next = parent->next->left;
    }
    if (node->left != nullptr)
        Dfs(node, node->left, true);
    if (node->right != nullptr)
        Dfs(node, node->right, false);
}

Node *LeetCode116PopulatingNextRightPointersInEachNode::connect(Node *root) {
    if (root == nullptr)
        return nullptr;
    root->next = nullptr;
    if (root->left != nullptr) {
        Dfs(root, root->left, true);
        Dfs(root, root->right, false);
    }
    return root;
}
#pragma  endregion
#pragma region BFS O(log(N)) memory
// Node * LeetCode116PopulatingNextRightPointersInEachNode::connect(Node *root) {
//     if(root == nullptr)
//         return nullptr;
//     std::queue<Node *> currentLayer{};
//     std::queue<Node *> nextLayer{};
//     currentLayer.push(root);
//     Node* node = nullptr;
//     Node* next = nullptr;
//     while(!currentLayer.empty()) {
//         while (!currentLayer.empty()) {
//             node = currentLayer.front();
//             currentLayer.pop();
//             next=nullptr;
//             if (!currentLayer.empty()) {
//                 next = currentLayer.front();
//             }
//             node->next = next;
//             if (node->left != nullptr) {
//                 nextLayer.push(node->left);
//             }
//             if (node->right != nullptr) {
//                 nextLayer.push(node->right);
//             }
//         }
//         while(!nextLayer.empty()) {
//             currentLayer.push(nextLayer.front());
//             nextLayer.pop();
//         }
//     }
//     return root;
// }
#pragma endregion
