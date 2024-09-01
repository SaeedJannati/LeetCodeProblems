#include "LeetCode101SymmetricTree.h"

void LeetCode101SymmetricTree::Run()
{
    
}
bool LeetCode101SymmetricTree::isSymmetric(TreeNode* root)
{
    if (root == nullptr)
        return true;
  return   Check(root->left, root->right);
}
bool LeetCode101SymmetricTree::Check(TreeNode* p,TreeNode* q)
{
    bool output = true;
    if(p==nullptr ^ q==nullptr)
        return false;
    if(p==nullptr && q ==nullptr)
        return true;
    if(p->val!=q->val)
        return false;
    output &= Check(p->left,q->right);
    output &= Check(p->right,q->left);
    return output;
}



