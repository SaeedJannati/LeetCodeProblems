using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode1372LongestZigZagPathinaBinaryTree : BaseProblemClass
{
    public int LongestZigZag(TreeNode root)
    {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 0;
        int maxLength = 0;
        Dfs(root, false, 0, ref maxLength);
        return maxLength;
    }

    private void Dfs(TreeNode node, bool justCameRight, int depth, ref int maxDepth)
    {
        var newNode = justCameRight ? node.left : node.right;
        if (newNode != null)
        {
            depth++;
            if (depth > maxDepth)
                maxDepth = depth;
            Dfs(newNode, !justCameRight, depth, ref maxDepth);
        }

        newNode = !justCameRight ? node.left : node.right;
        if (newNode != null)
            Dfs(newNode, justCameRight, 1, ref maxDepth);
    }

    public override void Run()
    {
        var root = TreeBuilder.BuildTree([1,null,2,3,4,null,null,null,5]);
        Console.WriteLine(LongestZigZag(root));
    }
}