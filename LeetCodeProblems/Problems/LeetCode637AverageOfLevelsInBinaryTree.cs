using System.Xml;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode637AverageOfLevelsInBinaryTree
{
    public IList<double> AverageOfLevels(TreeNode root)
    {
        if (root == null)
            return [];
        if (root.left == null && root.right == null)
            return [root.val];
        IList<double> output = [];
        Queue<TreeNode> layer = new ();
        Queue<TreeNode> nextLayer = new ();
        layer.Enqueue(root);
        decimal sum = 0;
        int count = 0;
        TreeNode current;
        while (layer.Count > 0)
        {
            sum = 0;
            count = 0;
            while (layer.Count > 0)
            {
                current = layer.Dequeue();
                if(current.left != null)
                    nextLayer.Enqueue(current.left);
                if(current.right != null)
                    nextLayer.Enqueue(current.right);
                sum += current.val;
                count++;
            }
            output.Add((double)sum / count);
            while (nextLayer.Count>0)
            {
                layer.Enqueue(nextLayer.Dequeue());
            }
        }

        return output;
    }
}