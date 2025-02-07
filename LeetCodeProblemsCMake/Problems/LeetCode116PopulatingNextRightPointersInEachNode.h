//
// Created by saeed on 2/7/25.
//

#ifndef LEETCODE116POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
#define LEETCODE116POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
#include <cstddef>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class LeetCode116PopulatingNextRightPointersInEachNode {
    Node* connect(Node* root);
};



#endif //LEETCODE116POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H
