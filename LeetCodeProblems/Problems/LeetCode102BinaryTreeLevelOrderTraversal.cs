using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode102BinaryTreeLevelOrderTraversal
{
    public IList<IList<int>> LevelOrder(TreeNode root)
    {
        if (root == null)
            return [];
        IList<IList<int>> result = [];
        Queue<TreeNode> currentLayer = [];
        Queue<TreeNode> nextLayer = [];
        currentLayer.Enqueue(root);
        TreeNode current = null;
        while (currentLayer.Count > 0)
        {
            IList<int> layer = [];
            while (currentLayer.Count > 0)
            {
                current=currentLayer.Dequeue();
                layer.Add(current.val);
                if(current.left != null)
                    nextLayer.Enqueue(current.left);
                if(current.right != null)
                    nextLayer.Enqueue(current.right);
            }
            result.Add([..layer]);
            while (nextLayer.Count>0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }
        }

        return result;
    }
}