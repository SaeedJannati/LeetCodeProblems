using System.Text;
using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode297SerializeAndDeserializeBinaryTree : BaseProblemClass
{
    public class Codec
    {
        // Encodes a tree to a single string.
        public string serialize(TreeNode root)
        {
            if (root == null)
                return "[]";
            if (root.left == null && root.right == null)
                return $"[{root.val}]";
            StringBuilder builder = new StringBuilder();
            builder.Append("[");
            Queue<TreeNode> currentLayer = [];
            Queue<TreeNode> nextLayer = [];
            TreeNode node;
            currentLayer.Enqueue(root);
            while (currentLayer.Count > 0)
            {
                while (currentLayer.Count > 0)
                {
                    node = currentLayer.Dequeue();
                    if (node == null)
                    {
                        builder.Append("null,");
                        continue;
                    }

                    builder.Append($"{node.val},");
                    nextLayer.Enqueue(node.left);
                    nextLayer.Enqueue(node.right);
                }

                bool hasNoneNull = false;
                while (nextLayer.Count > 0)
                {
                    node = nextLayer.Dequeue();
                    if (node != null)
                        hasNoneNull = true;
                    currentLayer.Enqueue(node);
                }

                if (!hasNoneNull)
                    break;
            }

            builder.Remove(builder.Length - 1, 1);
            builder.Append("]");
            return builder.ToString();
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize(string data)
        {
            if (data.Length <= 2)
                return null;
            data=data.Substring(1, data.Length - 2);
            var parts = data.Split(',');
            var values = new List<int?>(parts.Length);
            foreach (var part in parts)
            {
                int num = 0;
                if (int.TryParse(part, out num))
                {
                    values.Add(num);
                    continue;
                }

                values.Add(null);
            }
            int nodeCount = values.Count;
            if (nodeCount == 0)
                return null;
            int nextLevelLength = 2;
            int counter = 1;
            TreeNode root = new TreeNode(values[0].Value);
            if(counter==nodeCount)
                return root;
            Queue<TreeNode> previousLayer = [];
            Queue<TreeNode> currentLayer = [];
            TreeNode previousNode = null;
            TreeNode node = null;
            previousLayer.Enqueue(root);
            int? value;
            while (previousLayer.Count > 0)
            {
                while (previousLayer.Count > 0)
                {
                    previousNode = previousLayer.Dequeue();
                    value = values[counter];
                    if (value != null)
                    {
                        node = new TreeNode(value.Value);
                        previousNode.left = node;
                        currentLayer.Enqueue(node);
                    }

                    counter++;
                    if (counter >= nodeCount)
                        return root;

                    value = values[counter];
                    if (value != null)
                    {
                        node = new TreeNode(value.Value);
                        previousNode.right = node;
                        currentLayer.Enqueue(node);
                    }

                    counter++;
                    if (counter >= nodeCount)
                        return root;
                }

                while (currentLayer.Count > 0)
                {
                    previousLayer.Enqueue(currentLayer.Dequeue());
                }
            }

            return root;
        }
    }

    public override void Run()
    {
        // var node = TreeBuilder.BuildTree([1, 2, 3, null, null, 4, 5]);
        var serializer = new Codec();
      var  node = serializer.deserialize("[1]");
        Console.WriteLine(serializer.serialize(node));
    }
}