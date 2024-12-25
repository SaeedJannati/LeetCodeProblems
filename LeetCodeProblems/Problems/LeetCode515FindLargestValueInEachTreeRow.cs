using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode515FindLargestValueInEachTreeRow
{
    public IList<int> LargestValues(TreeNode root)
    {
        if (root == null)
            return [];
        if (root.left == null && root.right == null)
            return [root.val];
        Queue<TreeNode> currentLayer = [];
        Queue<TreeNode> nexLayer = [];
        IList<int> result = [];
        int max = int.MinValue;
        currentLayer .Enqueue(root);
        while (currentLayer.Count > 0)
        {
            while (currentLayer.Count > 0)
            {
                var node=currentLayer.Dequeue();
                if(node.val>max)
                    max=node.val;
                if(node.left != null)
                    nexLayer.Enqueue(node.left);
                if(node.right != null)
                    nexLayer.Enqueue(node.right);
            }

            result.Add(max);
            max = int.MinValue;
            while (nexLayer.Count > 0)
            {
                currentLayer.Enqueue(nexLayer.Dequeue());
            }
        }

        return result;
    }
}