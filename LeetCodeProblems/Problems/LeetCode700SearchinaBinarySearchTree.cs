using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode700SearchinaBinarySearchTree
{
    public TreeNode SearchBST(TreeNode root, int val) {
        return Find(root, val);
    }

    private TreeNode? Find(TreeNode root, int val)
    {
        if(val == root.val)
            return root;
        if (val < root.val)
        {
            if(root.left != null)
                return Find(root.left, val);
        }
        if(root.right != null)
            return Find(root.right, val);
        return null;
    }
}