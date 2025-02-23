using System.Text;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Auxilaries;

public class TreePrinter
{
    public static void PrintInOrderTraversal(TreeNode root)
    {
        StringBuilder builder = new();
        InOrder(root, builder);
        Console.WriteLine(builder.ToString());
    }

    private static void InOrder(TreeNode node, StringBuilder builder)
    {
        builder.Append($"{node.val},");
        if(node.left != null)
            InOrder(node.left, builder);
        if (node.right != null)
            InOrder(node.right, builder);
    }
}