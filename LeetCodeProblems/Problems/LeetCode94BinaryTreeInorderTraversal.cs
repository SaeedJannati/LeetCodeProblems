using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode94BinaryTreeInorderTraversal
{
    public IList<int> InorderTraversal(TreeNode root)
    {
        if (root == null)
            return [];
        IList<int> inorder = [];
        InorderTraversal(root, inorder);
        return inorder;
    }

    private void InorderTraversal(TreeNode node, IList<int> list)
    {
        if(node.left != null)
            InorderTraversal(node.left, list);
        list.Add(node.val);
        if(node.right != null)
            InorderTraversal(node.right, list);
    }
}