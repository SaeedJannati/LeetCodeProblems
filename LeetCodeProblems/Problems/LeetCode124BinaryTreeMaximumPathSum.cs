using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode124BinaryTreeMaximumPathSum
{
    public int MaxPathSum(TreeNode root)
    {
        int max = int.MinValue;
        Dictionary<TreeNode, int> dp = [];
        CalcRightAndLeftMax(root,ref max, dp);
        return max;
    }

    int CalcRightAndLeftMax(TreeNode node, ref int sum,Dictionary<TreeNode,int>dp)
    {
        if(dp.TryGetValue(node, out var maxPath))
            return maxPath;
        int max = node.val;
        int left = 0, right = 0;
        if (node.left != null)
           left=  CalcRightAndLeftMax(node.left, ref sum,dp);
        if (node.right != null)
          right= CalcRightAndLeftMax(node.right, ref sum,dp);
        if (left > 0)
            max += left;
        if (right > 0)
            max += right;
        if(max>sum)
            sum = max;
        dp[node]=node.val+Math.Max(Math.Max(left,right),0);
        return dp[node];
    }
}