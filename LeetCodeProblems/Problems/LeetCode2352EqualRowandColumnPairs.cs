namespace LeetCodeProblems.Problems;

public class LeetCode2352EqualRowandColumnPairs: BaseProblemClass
{
    public int EqualPairs(int[][] grid)
    {
        var root = new TrieNode(grid);
        var current = root;
        TrieNode node = null;
        int output = 0;
        int similaritesCount = 0;
        bool notFound = false;
        var length = grid.Length;
        for (int i = 0; i < length; i++)
        {
            current = root;
            similaritesCount = 0;
            for (int j = 0; j < length; j++)
            {
                if (!current.children.TryGetValue(grid[j][i], out node))
                    break;
                current = node;
                similaritesCount++;
            }

            if (similaritesCount == length)
                output+=current.count;
        }
        return output;
    }


    public class TrieNode
    {
        public TrieNode()
        {
        }

        public TrieNode(int[][] grid)
        {

            var currentNode = this;
            TrieNode node=null;
            for (int i = 0, e = grid.Length; i < e; i++)
            {
                currentNode = this;
                for (int j = 0; j < e; j++)
                {
                    if (!currentNode.children.TryGetValue(grid[i][j], out node))
                    {
                        node = new TrieNode();
                        currentNode.children.Add(grid[i][j], node);
                    }

                    currentNode = node;
                }

                node.count++;
            }
        }

        public int count = 0;
        public readonly Dictionary<int, TrieNode> children = [];
    }

    public override void Run()
    {
        int[][] grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]];
        var count = EqualPairs(grid);
        Console.WriteLine($"Count: {count}");
    }
}