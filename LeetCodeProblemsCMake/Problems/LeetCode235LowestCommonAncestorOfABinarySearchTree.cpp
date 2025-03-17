//
// Created by saeed on 3/17/25.
//

#include "LeetCode235LowestCommonAncestorOfABinarySearchTree.h"

#include <utility>

#include "../Auxilary/Auxilaries.h"
#include "../Auxilary/TreeNode.h"
using namespace std;

pair<bool, bool> Recurse(TreeNode* node,TreeNode* p,TreeNode* q,TreeNode* result) {
    pair<bool, bool> res{false,false};
    if (node->val == p->val) {
        res.first = true;
    }
    if (node->val == q->val) {
        res.second = true;
    }

    pair<bool, bool> leftRes{false,false};
    if (node->left!= nullptr ) {
        leftRes = Recurse(node->left,p,q,result);
        if (leftRes.first && leftRes.second) {
            return {true,true};
        }
    }
    pair<bool, bool> rightRes{false,false};
    if (node->right!= nullptr ) {
        rightRes = Recurse(node->right,p,q,result);
        if (rightRes.first && rightRes.second) {
            return {true,true};
        }
    }
    if (!res.first) {
        res.first = leftRes.first||rightRes.first;
    }
    if (!res.second) {
        res.second = leftRes.second||rightRes.second;
    }
    if (res.first && res.second) {
        result=node;
    }
    return res;
}
TreeNode * LeetCode235LowestCommonAncestorOfABinarySearchTree::lowestCommonAncestor(TreeNode *root, TreeNode *p,
    TreeNode *q) {
    TreeNode* result=nullptr;
    if(root == nullptr)
        return nullptr;
    Recurse(root,p,q,result);
    return result;
}

void LeetCode235LowestCommonAncestorOfABinarySearchTree::Run() {

}
