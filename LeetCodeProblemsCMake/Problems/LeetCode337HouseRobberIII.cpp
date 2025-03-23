//
// Created by saeed on 3/23/25.
//

#include "LeetCode337HouseRobberIII.h"

#include <unordered_map>
#include <vector>

#include "../Auxilary/TreeNode.h"
using namespace std;

pair<int, int> CalcMaxMoneyOfNode(TreeNode *node, unordered_map<TreeNode *, pair<int, int> > &memoisation) {
    if (node == nullptr)
        return {0, 0};
    if (memoisation.contains(node))
        return memoisation[node];
    auto leftInfo=CalcMaxMoneyOfNode(node->left, memoisation);
    auto rightInfo=CalcMaxMoneyOfNode(node->right, memoisation);
    int maxWith = node->val + leftInfo.second + rightInfo.second;
    int maxWithout =  max(leftInfo.first,leftInfo.second) +max(rightInfo.first,rightInfo.second); ;
    memoisation[node] = {maxWith, maxWithout};
    return memoisation[node];
}

int LeetCode337HouseRobberIII::rob(TreeNode *root) {
    unordered_map<TreeNode *, pair<int, int> > memoisation{};
    auto rootInfo = CalcMaxMoneyOfNode(root, memoisation);
    return max(rootInfo.first,rootInfo.second);
}
