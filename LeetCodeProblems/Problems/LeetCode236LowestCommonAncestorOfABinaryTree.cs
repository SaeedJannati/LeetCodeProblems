using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode236LowestCommonAncestorOfABinaryTree
{
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        return GetNodesInSubtree(root, p.val, q.val).node;
    }

    (HashSet<int> children,bool found,TreeNode node) GetNodesInSubtree(TreeNode root, int p, int q)
    {
        HashSet<int> outPut = [root.val];
        if (root.left != null)
        {
            var leftOutput=GetNodesInSubtree(root.left, p, q);
            if(leftOutput.found)
                return ([],true,leftOutput.node);
            outPut = [..outPut, ..leftOutput.children];
            if (outPut.Contains(p) && outPut.Contains(q))
                return ([],true,root);
        }

     
        if (root.right != null)
        {
            var rightOutput=GetNodesInSubtree(root.right, p, q);
            if(rightOutput.found)
                return ([],true,rightOutput.node);
            outPut = [..outPut, ..rightOutput.children];
        }
  
        if (outPut.Contains(p) && outPut.Contains(q))
            return ([],true,root);
        return (outPut,false,root);
        }
    }
