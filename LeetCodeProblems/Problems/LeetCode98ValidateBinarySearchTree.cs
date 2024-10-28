using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode98ValidateBinarySearchTree
{
    public bool IsValidBST(TreeNode root)
    {
        if (root == null)
            return true;
        if (root.left == null && root.right == null)
            return true;
        List<int> inOrderTraversal = [];
        GetInOrderTraversal(root, inOrderTraversal);
        for (int i = 0,e=inOrderTraversal.Count-1; i < e; i++)
        {
            if (inOrderTraversal[i+1] <= inOrderTraversal[i])
                return false;
        }

        return true;
    }

    private void GetInOrderTraversal(TreeNode root, List<int> result)
    {
        if (root.left != null)
            GetInOrderTraversal(root.left, result);
        result.Add(root.val);
        if(root.right != null)
            GetInOrderTraversal(root.right, result);
    }
}