﻿#pragma once

#include "BaseProblem.h"
class Node;
class LeetCode117PopulatingNextRightPointersInEachNodeII: BaseProblem
{
public:
    void Run() override;
private:
    Node* connect(Node* root);
};
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

