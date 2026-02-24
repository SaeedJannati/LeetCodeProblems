//
// Created by Saeed Jannati on 2/24/2026 A.
//

#include "LeetCode1022SumOfRootToLeafBinaryNumbers.h"

#include "../Auxilary/TreeNode.h"

void dfs(TreeNode* node,int current, int& sum) {
    if (node==nullptr) {
        return;
    }
    current= (current<<1)|(node->val);
    if (node->left==nullptr && node->right==nullptr) {
        sum+=current;
        return;
    }
    dfs(node->left,current,sum);
    dfs(node->right,current,sum);
}
int LeetCode1022SumOfRootToLeafBinaryNumbers::sumRootToLeaf(TreeNode *root) {
    int sum=0;
    dfs(root,0,sum);
    return sum;
}
