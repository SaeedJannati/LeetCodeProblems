//
// Created by saeed on 1/16/25.
//

#include "LeetCode113PathSumII.h"

#include "../Auxilary/TreeNode.h"

void Dfs(TreeNode* node,int currentSum,std::vector<int> currentPath,std::vector<std::vector<int>>& result,int targetSum) {
    currentSum+=node->val;
    currentPath.push_back(node->val);
    if(node->left==nullptr && node->right==nullptr) {
        if (currentSum == targetSum) {
            result.push_back(currentPath);
        }
        return;
    }
    if(node->left!=nullptr)
        Dfs(node->left,currentSum,currentPath,result,targetSum);
    if(node->right!=nullptr)
        Dfs(node->right,currentSum,currentPath,result,targetSum);
}
std::vector<std::vector<int>> LeetCode113PathSumII::pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
        return {};
    std::vector<std::vector<int>> result;
    std::vector<int> currentPath;
    Dfs(root,0,currentPath,result,targetSum);
    return result;
}
