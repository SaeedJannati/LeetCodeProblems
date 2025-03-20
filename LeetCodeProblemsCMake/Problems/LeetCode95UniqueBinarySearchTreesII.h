//
// Created by saeed on 3/20/25.
//

#ifndef LEETCODE95UNIQUEBINARYSEARCHTREESII_H
#define LEETCODE95UNIQUEBINARYSEARCHTREESII_H
#include <vector>

#include "BaseProblem.h"


struct TreeNode;

class LeetCode95UniqueBinarySearchTreesII: BaseProblem {
    private:
    std::vector<TreeNode*> generateTrees(int n);
    public:
    void Run() override;
};



#endif //LEETCODE95UNIQUEBINARYSEARCHTREESII_H
