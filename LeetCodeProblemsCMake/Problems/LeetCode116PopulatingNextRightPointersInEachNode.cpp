//
// Created by saeed on 2/7/25.
//

#include "LeetCode116PopulatingNextRightPointersInEachNode.h"

#include <queue>

Node * LeetCode116PopulatingNextRightPointersInEachNode::connect(Node *root) {
    if(root == nullptr)
        return nullptr;
    std::queue<Node *> currentLayer{};
    std::queue<Node *> nextLayer{};
    currentLayer.push(root);
    Node* node = nullptr;
    Node* next = nullptr;
    while(!currentLayer.empty()) {
        while (!currentLayer.empty()) {
            node = currentLayer.front();
            currentLayer.pop();
            next=nullptr;
            if (!currentLayer.empty()) {
                next = currentLayer.front();
            }
            node->next = next;
            if (node->left != nullptr) {
                nextLayer.push(node->left);
            }
            if (node->right != nullptr) {
                nextLayer.push(node->right);
            }
        }
        while(!nextLayer.empty()) {
            currentLayer.push(nextLayer.front());
            nextLayer.pop();
        }
    }
    return root;
}
