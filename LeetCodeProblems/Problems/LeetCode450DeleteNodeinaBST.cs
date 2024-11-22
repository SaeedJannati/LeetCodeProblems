using LeetCodeProblems.Auxilaries;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode450DeleteNodeinaBST : BaseProblemClass
{
    public TreeNode DeleteNode(TreeNode root, int key)
    {
        if (root == null)
            return root;
        var result = FindNode(root, key);
        if (result.node == null)
            return root;
        if (result.node.left == null && result.node.right == null)
        {
            if (result.parent == null)
                return null;
            if (result.parent.left == result.node)
                result.parent.left = null;
            else
                result.parent.right = null;
            return root;
        }

        if (result.node.left == null)
        {
            if (result.parent == null)
                return result.node.right;
            if (result.parent.left == result.node)
                result.parent.left = result.node.right;
            else
                result.parent.right = result.node.right;

            return root;
        }

        if (result.node.right == null)
        {
            if (result.parent == null)
                return result.node.left;
            if (result.parent.left == result.node)
                result.parent.left = result.node.left;
            else
                result.parent.right = result.node.left;

            return root;
        }

        var mostRight = FindMostRightInLeft(result.node);
        mostRight.right = result.node.right;
        if (result.parent == null)
            return result.node.left;
        if (result.parent.left == result.node)
            result.parent.left = result.node.left;
        else
            result.parent.right = result.node.left;
        return root;
    }

    TreeNode FindMostRightInLeft(TreeNode node)
    {
        var current = node.left;
        while (current.right != null)
        {
            current = current.right;
        }

        return current;
    }

    (TreeNode? node, TreeNode? parent) FindNode(TreeNode root, int key)
    {
        TreeNode previous = null;
        var current = root;
        while (true)
        {
            if (current.val == key)
                return (current, previous);
            if (key > current.val)
            {
                if (current.right == null)
                    return (null, null);
                previous = current;
                current = current.right;
                continue;
            }

            if (current.left == null)
                return (null, null);
            previous = current;
            current = current.left;
        }
    }

    public override void Run()
    {
        var root = TreeBuilder.BuildTree([2, 1, 3]);
        int key = 1;
        DeleteNode(root, key);
    }
}