using System.ComponentModel.DataAnnotations;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode530MinimumAbsoluteDifferenceinBST
{
    public int GetMinimumDifference(TreeNode root)
    {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 0;
        var inOrderTraversal = new List<int>();
        InOrderTraversal(root, inOrderTraversal);
        int min = int.MaxValue;
        int delta = 0;
        for (int i = 0, e = inOrderTraversal.Count - 1; i < e; i++)
        {
            delta=Math.Abs(inOrderTraversal[i]-inOrderTraversal[i+1]);
            if(delta<min)
                min=delta;
        }

        return min;
    }

    void InOrderTraversal(TreeNode root, List<int> result)
    {
        if (root.left != null)
        {
            InOrderTraversal(root.left, result);
        }

        result.Add(root.val);
        if (root.right != null)
        {
            InOrderTraversal(root.right, result);
        }
    }
}