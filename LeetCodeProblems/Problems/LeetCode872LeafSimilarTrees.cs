using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode872LeafSimilarTrees
{
    public bool LeafSimilar(TreeNode root1, TreeNode root2)
    {
        if (root1 == null && root2 == null)
            return true;
        if (root1 == null || root2 == null)
            return false;
        List<int> firstLeaves = [];
        GetLeaves(root1,firstLeaves);
        List<int> secondLeaves = [];
        GetLeaves(root2, secondLeaves);
        if (firstLeaves.Count != secondLeaves.Count)
            return false;
        for (int i = 0, e = firstLeaves.Count; i < e; i++)
        {
            if (firstLeaves[i] != secondLeaves[i])
                return false;
        }

        return true;
    }

    private void GetLeaves(TreeNode node, List<int> leaves)
    {
        if (node.left == null && node.right == null)
        {
            leaves.Add(node.val);
            return;
        }

        if (node.left != null)
            GetLeaves(node.left, leaves);
        if(node.right != null)
            GetLeaves(node.right, leaves);
    }
}