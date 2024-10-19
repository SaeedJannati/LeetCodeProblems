using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode114FlattenBinaryTreeToLinkedList
{
    public void Flatten(TreeNode root)
    {
        if (root == null)
            return;
        List<int> values = new();
        CreateSubTreePreorder(root, values);
        root.left = null;
        TreeNode previous = root;
        TreeNode currTreeNode = null;
        for (int i = 1; i < values.Count; i++)
        {
            currTreeNode = new TreeNode(values[i]);
            previous.right = currTreeNode;
            previous = currTreeNode;
        }
    }

    private void CreateSubTreePreorder(TreeNode root, List<int> values)
    {
        values.Add(root.val);
        if (root.left != null)
            CreateSubTreePreorder(root.left, values);
        if (root.right != null)
            CreateSubTreePreorder(root.right, values);
    }
}