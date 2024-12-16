using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode543DiameterOfBinaryTree
{
    public int DiameterOfBinaryTree(TreeNode root)
    {
        int diameter = 0;
        Dfs(root, ref diameter);
        return diameter;
    }

    int Dfs(TreeNode node, ref int currentDiameter)
    {
        int leftDepth = 0;
        int rightDepth = 0;
        int diameter = 0;
        if (node.left != null)
        {
            leftDepth = Dfs(node.left, ref currentDiameter);
            leftDepth++;
        }


        if (node.right != null)
        {
            rightDepth = Dfs(node.right, ref currentDiameter);
            rightDepth++;
        }


        diameter = leftDepth + rightDepth;
        if (diameter > currentDiameter)
            currentDiameter = diameter;
        return Math.Max(leftDepth , rightDepth );
    }
}