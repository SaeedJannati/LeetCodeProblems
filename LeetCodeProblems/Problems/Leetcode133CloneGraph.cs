namespace LeetCodeProblems.Problems;

public class Leetcode133CloneGraph
{
    Dictionary<int, Node> nodes = [];

    public Node CloneGraph(Node node)
    {
        if (node == null)
            return node;
        return CloneNode(node);
    }

    Node CloneNode(Node node)
    {
        if (nodes.ContainsKey(node.val))
            return nodes[node.val];
        var aNode = new Node(node.val);
        if (node.neighbors == null)
            return aNode;
        if (node.neighbors.Count == 0)
            return aNode;
        aNode.neighbors = new List<Node>(node.neighbors.Count);

        nodes[aNode.val] = aNode;
        for (int i = 0, e = node.neighbors.Count; i < e; i++)
        {
            aNode.neighbors.Add(CloneNode(node.neighbors[i]));
        }

        return aNode;
    }
}