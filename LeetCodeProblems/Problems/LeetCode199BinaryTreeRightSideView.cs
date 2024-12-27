using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode199BinaryTreeRightSideView
{
    public IList<int> RightSideView(TreeNode root)
    {
        if (root == null)
            return [];
        if (root.left == null && root.right == null)
            return [root.val];
        IList<int> output = [];
        Queue<TreeNode> currentLayer = [];
        Queue<TreeNode> nextLayer = [];
        currentLayer.Enqueue(root);
        while (currentLayer.Count != 0)
        {
            output.Add(currentLayer.Peek().val);
            while (currentLayer.Count != 0)
            {
                var node = currentLayer.Dequeue();
                if(node.right != null)
                    nextLayer.Enqueue(node.right);
                if(node.left != null)
                    nextLayer.Enqueue(node.left);
                
            }

            while (nextLayer.Count != 0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }
        }

        return output;
    }
}