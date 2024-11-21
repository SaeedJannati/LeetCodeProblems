using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode212WordSearchII : BaseProblemClass
{
    public IList<string> FindWords(char[][] board, string[] words)
    {
        var result = new List<string>();
        var root = BuildTrie(words);
        int height = board.Length, width = board[0].Length;

        bool[,] visited = new bool[height, width];

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Backtrack(board, i, j, root, visited, result);
            }
        }

        return result;
    }

    private void Backtrack(char[][] board, int i, int j, TrieNode node, bool[,] visited, IList<string> result)
    {
        if (i < 0 || i >= board.Length || j < 0 || j >= board[0].Length || visited[i, j] ||
            !node.Children.TryGetValue(board[i][j],out var nextNode))
        {
            return;
        }
        if (nextNode.Word != null)
        {
            result.Add(nextNode.Word);
            nextNode.Word = null; 
        }
        visited[i, j] = true;
        Backtrack(board, i + 1, j, nextNode, visited, result);
        Backtrack(board, i - 1, j, nextNode, visited, result);
        Backtrack(board, i, j + 1, nextNode, visited, result);
        Backtrack(board, i, j - 1, nextNode, visited, result);
        visited[i, j] = false;
    }

    private TrieNode BuildTrie(string[] words)
    {
        var root = new TrieNode();
        foreach (var word in words)
        {
            var current = root;
            foreach (var c in word)
            {
                if (!current.Children.ContainsKey(c))
                {
                    current.Children[c] = new TrieNode();
                }

                current = current.Children[c];
            }

            current.Word = word; 
        }

        return root;
    }

    public class TrieNode
    {
        public readonly Dictionary<char, TrieNode> Children = new();
        public string? Word;
    }

    public override void Run()
    {
        char[][] board =
        [
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b']
        ];
        // [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'], ['i', 'h', 'k', 'r'], ['i', 'f', 'l', 'v']]
        string[] words =
        [
            "aababababa", "abbabababa", "acbabababa", "adbabababa", "aebabababa", "afbabababa", "agbabababa",
            "ahbabababa"
        ];
        // ["oath", "pea", "eat", "rain", "hklf", "hf"];
        Console.WriteLine(JsonSerializer.Serialize(FindWords(board, words)));
    }
}