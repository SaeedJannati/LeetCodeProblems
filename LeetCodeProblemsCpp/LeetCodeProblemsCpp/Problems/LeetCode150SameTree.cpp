#include "LeetCode150SameTree.h"

void LeetCode150SameTree::Run()
{
    
}

bool LeetCode150SameTree::isSameTree(TreeNode* p, TreeNode* q)
{
    if(p==nullptr && q==nullptr)
        return true;
    CheckIfSame(p,q);
}
bool LeetCode150SameTree::CheckIfSame(TreeNode* pNode,TreeNode* qNode)
{
    bool outPut=true;
    if(pNode==nullptr ^ qNode==nullptr)
        return false;
    if(pNode==nullptr && qNode ==nullptr)
        return true;
    if(pNode->val != qNode->val)
        return false;
   outPut &= CheckIfSame(pNode->left,qNode->left);
  outPut &=  CheckIfSame(pNode->right,qNode->right);
    return outPut;
}



