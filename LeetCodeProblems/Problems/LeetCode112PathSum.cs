using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode112PathSum
{
    public bool HasPathSum(TreeNode root, int targetSum)
    {
        if (root == null)
            return targetSum == 0;
        return CheckPathSumSubTree(root, targetSum, 0);
    }

    bool CheckPathSumSubTree(TreeNode node, int targetSum, int currentSum)
    {
        bool outPut = false;
        if (node.left == null && node.right == null)
            return currentSum + node.val == targetSum;
        if (node.left != null)
            outPut |= CheckPathSumSubTree(node.left, targetSum, currentSum + node.val);
        if (node.right != null)
            outPut |= CheckPathSumSubTree(node.right, targetSum, currentSum + node.val);
        return outPut;
    }
}