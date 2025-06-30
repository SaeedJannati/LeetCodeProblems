//
// Created by saeed on 6/30/25.
//

#ifndef LEETCODE429NARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE429NARYTREELEVELORDERTRAVERSAL_H
#include <vector>


class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class LeetCode429NaryTreeLevelOrderTraversal {
    std::vector<std::vector<int>> levelOrder(Node* root);
};



#endif //LEETCODE429NARYTREELEVELORDERTRAVERSAL_H
