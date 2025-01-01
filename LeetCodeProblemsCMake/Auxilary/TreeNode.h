//
// Created by saeed on 1/2/25.
//

#ifndef TREENODE_H
#define TREENODE_H



struct  TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
    static void PrintPreOrder(TreeNode* root);
    static void PrintInOrder(TreeNode* root);
    static void PrintPostOrder(TreeNode* root);

};



#endif //TREENODE_H
