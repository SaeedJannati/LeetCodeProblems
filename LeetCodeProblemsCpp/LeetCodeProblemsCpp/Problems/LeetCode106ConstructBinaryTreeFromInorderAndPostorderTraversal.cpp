#include "LeetCode106ConstructBinaryTreeFromInorderAndPostorderTraversal.h"

#include <iostream>
#include <map>
#include <ostream>

void LeetCode106ConstructBinaryTreeFromInorderAndPostorderTraversal::Run()
{
    std::vector<int> inorder={9,3,15,20,7};
    std::vector<int> postorder{9,15,7,20,3};

    auto root=buildTree(inorder,postorder);
    std::cout<<"Inorder Traversal: ";
    TreeNode::PrintInOrder(root);
    std::cout<<'\n'<<"Postorder Traversal: ";
    TreeNode::PrintPostOrder(root);
    
}
TreeNode* LeetCode106ConstructBinaryTreeFromInorderAndPostorderTraversal::buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    int size=static_cast<int>(inorder.size());
    if(size==0)
        return nullptr;
    if(size==1)
        return new TreeNode(inorder[0]);

    std::map<int,int> inorderMap;
    for(int i=0;i<size;i++)
        inorderMap[inorder[i]]=i;
    TreeNode* root=GenerateSubTree(inorderMap,postorder,size-1,0,size-1);
    return root;
}
TreeNode* LeetCode106ConstructBinaryTreeFromInorderAndPostorderTraversal::GenerateSubTree( std::map<int,int>& inorderMap,  std::vector<int>& postorder,int rootPostorderIndex,int beginInorderIndex,int endInorderIndex)
{
    if(beginInorderIndex>endInorderIndex)
        return nullptr;
    auto root=new TreeNode(postorder[rootPostorderIndex]);
    int rootInorderIndex=inorderMap[root->val];
    int rightTreeLength=endInorderIndex-rootInorderIndex;
    int rightTreeRootIndex=rootPostorderIndex-1;
    int leftTreeRoot=rootPostorderIndex-1-rightTreeLength ;
    root->left=GenerateSubTree(inorderMap,postorder,leftTreeRoot,beginInorderIndex,rootInorderIndex-1);
    root->right=GenerateSubTree(inorderMap,postorder,rightTreeRootIndex,rootInorderIndex+1,endInorderIndex);
    return root;
}

