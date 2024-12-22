using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode572SubtreeOfAnotherTree
{
    public bool IsSubtree(TreeNode root, TreeNode subRoot)
    {
        Queue<TreeNode> queue = new();
        queue.Enqueue(root);
        TreeNode node = null;
        bool areSame;
        while (queue.Count > 0)
        {
            node = queue.Dequeue();
            if (node.val == subRoot.val)
            {
                areSame = true;
                CheckIfSame(node, subRoot, ref areSame);
                if (areSame)
                    return true;
            }

            if (node.left != null)
                queue.Enqueue(node.left);
            if (node.right != null)
                queue.Enqueue(node.right);
        }

        return false;
    }

    private void CheckIfSame(TreeNode source, TreeNode target, ref bool areSame)
    {
        if (!areSame)
            return;
        if (source.val != target.val)
            areSame = false;
        if (target.left == null && source.left != null)
            areSame = false;
        if (target.right == null && source.right != null)
            areSame = false;
        if (target.left != null)
        {
            if (source.left == null)
                areSame = false;
            CheckIfSame(source.left, target.left, ref areSame);
        }

        if (target.right != null)
        {
            if (source.right == null)
                areSame = false;
            CheckIfSame(source.right, target.right, ref areSame);
        }
    }
}