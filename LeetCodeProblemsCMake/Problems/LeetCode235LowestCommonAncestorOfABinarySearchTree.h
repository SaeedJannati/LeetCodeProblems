//
// Created by saeed on 3/17/25.
//

#ifndef LEETCODE235LOWESTCOMMONANCESTOROFABINARYSEARCHTREE_H
#define LEETCODE235LOWESTCOMMONANCESTOROFABINARYSEARCHTREE_H
#include "BaseProblem.h"


struct TreeNode;

class LeetCode235LowestCommonAncestorOfABinarySearchTree: BaseProblem {
private:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    public:
    void Run() override;
};



#endif //LEETCODE235LOWESTCOMMONANCESTOROFABINARYSEARCHTREE_H
