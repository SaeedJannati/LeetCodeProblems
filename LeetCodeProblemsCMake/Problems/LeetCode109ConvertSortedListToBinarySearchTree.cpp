//
// Created by saeed on 1/14/25.
//

#include "LeetCode109ConvertSortedListToBinarySearchTree.h"

#include <vector>

#include "../Auxilary/ListNode.h"
#include "../Auxilary/TreeNode.h"
TreeNode* ConstructSubtree(std::vector<int>& nums,int begin,int end) {
    if (begin>end)
        return nullptr;
    if (begin<0)
        return nullptr;
    if (begin==end) {
        auto root=new TreeNode(nums[begin]);
        return root;
    }
    int rootIndex=(begin+end)/2;
    auto root=new TreeNode(nums[rootIndex]);
    root->left=ConstructSubtree(nums,begin,rootIndex-1);
    root->right=ConstructSubtree(nums,rootIndex+1,end);
    return root;
}
TreeNode * LeetCode109ConvertSortedListToBinarySearchTree::sortedListToBST(ListNode *head) {
    if (head == nullptr)
        return nullptr;
    std::vector<int> nums;
    auto node=head;
    while(node!=nullptr) {
        nums.push_back(node->val);
        node=node->next;
    }
 return ConstructSubtree(nums,0,nums.size()-1);
}

