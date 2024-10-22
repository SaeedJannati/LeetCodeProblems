using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode173BinarySearchTreeIterator
{
}

public class BSTIterator
{
    Queue<int> values = [];

    public BSTIterator(TreeNode root)
    {
        GetInOrderSubTreeValue(root);
    }

    private void GetInOrderSubTreeValue(TreeNode node)
    {
        if (node.left != null)
            GetInOrderSubTreeValue(node.left);
        values.Enqueue(node.val);
        if(node.right != null)
            GetInOrderSubTreeValue(node.right);
    }

    public int Next()
    {
        return values.Dequeue();
    }

    public bool HasNext()
    {
        return values.Count > 0;
    }
}