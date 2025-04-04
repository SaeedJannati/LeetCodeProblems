using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode1123LowestCommonAncestorOfDeepestLeaves: BaseProblemClass
{
    public TreeNode LcaDeepestLeaves(TreeNode root)
    {
        TreeNode answer = null;
        int maxDepth = 0;
        PostOrderDepth(root, ref maxDepth, 0,ref answer);
        return answer;
    }

    int PostOrderDepth(TreeNode node, ref int maxDepth, int depth,ref TreeNode answer)
    {
        if (depth > maxDepth)
            maxDepth = depth;
        int leftDepth = depth;
        int rightDepth = depth;
        if (node.left != null)
        {
            leftDepth = PostOrderDepth(node.left, ref maxDepth, depth + 1,ref answer);
        }

        if (node.right != null)
        {
            rightDepth = PostOrderDepth(node.right, ref maxDepth, depth + 1,ref answer);
        }

        if (leftDepth == maxDepth && rightDepth == maxDepth)
        {
            answer = node;
        }

        return int.Max(leftDepth, rightDepth);
    }

    public override void Run()
    {
        var root = TreeBuilder.BuildTree([3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]);
        root = LcaDeepestLeaves(root);
        Console.WriteLine(root.val);
    }
}