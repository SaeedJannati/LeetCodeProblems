using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode103BinaryTreeZigzagLevelOrderTraversal
{
    public IList<IList<int>> ZigzagLevelOrder(TreeNode root)
    {
        if (root == null)
            return [];
        if (root.left == null && root.right == null)
            return [[root.val]];
        IList<IList<int>> outPut = [];
        IList<int> layer = [];
        Queue<TreeNode> currentLayer = [];
        Stack<TreeNode> nextLayer = [];
        TreeNode current;
        currentLayer.Enqueue(root);
        bool leftToRight = true;
        while (currentLayer.Count > 0)
        {
            layer = [];
            while (currentLayer.Count > 0)
            {
                current = currentLayer.Dequeue();
                layer.Add(current.val);
                if (leftToRight)
                {
                    if (current.left != null)
                        nextLayer.Push(current.left);
                    if (current.right != null)
                        nextLayer.Push(current.right);
                    continue;
                }

                if (current.right != null)
                    nextLayer.Push(current.right);
                if (current.left != null)
                    nextLayer.Push(current.left);
            }

            outPut.Add(layer);
            while (nextLayer.Count > 0)
            {
                currentLayer.Enqueue(nextLayer.Pop());
            }

            leftToRight = !leftToRight;
        }

        return outPut;
    }
}