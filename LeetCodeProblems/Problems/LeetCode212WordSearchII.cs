using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode212WordSearchII : BaseProblemClass
{
    #region My solution

    public IList<string> FindWords(char[][] board, string[] words)
    {
        TrieNode root = new TrieNode(words);
        int height = board.Length;
        int width = board[0].Length;
        bool[,] visited = new bool[height, width];
        IList<string> result = [];

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                Search(root, result, board, visited, i, j, height, width);
            }
        }

        return result;
    }

    private void Search(TrieNode node, IList<string> result, char[][] board, bool[,] visited, int height, int width,
        int boardHeight, int boardWidth)
    {
        if (height < 0 || height >= boardHeight)
            return;
        if (width < 0 || width >= boardWidth)
            return;
        if (visited[height, width])
            return;
        if (!node.Children.TryGetValue(board[height][width], out var child))
            return;
        if (child.Word != null)
        {
            result.Add(child.Word);
            child.Word = null;
        }

        visited[height, width] = true;

        Search(child, result, board, visited, height, width+1, boardHeight, boardWidth);
        Search(child, result, board, visited, height, width-1, boardHeight, boardWidth);
        Search(child, result, board, visited, height+1, width, boardHeight, boardWidth);
        Search(child, result, board, visited, height-1, width, boardHeight, boardWidth);
        visited[height, width] = false;
    }


    public class TrieNode
    {
        public TrieNode()
        {
        }

        public TrieNode(string[] words)
        {
            foreach (var word in words)
            {
                var node = this;
                TrieNode child = null;
                foreach (var character in word)
                {
                    if (!node.Children.TryGetValue(character, out child))
                    {
                        child = new TrieNode();
                        node.Children.Add(character, child);
                    }

                    node = child;
                }

                node.Word = word;
            }
        }

        public Dictionary<char, TrieNode> Children = [];
        public string? Word { get; set; } = null;
    }

    #endregion

    #region GptSolution

    // public IList<string> FindWords(char[][] board, string[] words)
    // {
    //     var result = new List<string>();
    //     var root = BuildTrie(words);
    //     int height = board.Length, width = board[0].Length;
    //
    //     bool[,] visited = new bool[height, width];
    //
    //     for (int i = 0; i < height; i++)
    //     {
    //         for (int j = 0; j < width; j++)
    //         {
    //             Backtrack(board, i, j, root, visited, result);
    //         }
    //     }
    //
    //     return result;
    // }
    //
    // private void Backtrack(char[][] board, int i, int j, TrieNode node, bool[,] visited, IList<string> result)
    // {
    //     if (i < 0 || i >= board.Length || j < 0 || j >= board[0].Length || visited[i, j] ||
    //         !node.Children.TryGetValue(board[i][j],out var nextNode))
    //     {
    //         return;
    //     }
    //     if (nextNode.Word != null)
    //     {
    //         result.Add(nextNode.Word);
    //         nextNode.Word = null; 
    //     }
    //     visited[i, j] = true;
    //     Backtrack(board, i + 1, j, nextNode, visited, result);
    //     Backtrack(board, i - 1, j, nextNode, visited, result);
    //     Backtrack(board, i, j + 1, nextNode, visited, result);
    //     Backtrack(board, i, j - 1, nextNode, visited, result);
    //     visited[i, j] = false;
    // }
    //
    // private TrieNode BuildTrie(string[] words)
    // {
    //     var root = new TrieNode();
    //     foreach (var word in words)
    //     {
    //         var current = root;
    //         foreach (var c in word)
    //         {
    //             if (!current.Children.ContainsKey(c))
    //             {
    //                 current.Children[c] = new TrieNode();
    //             }
    //
    //             current = current.Children[c];
    //         }
    //
    //         current.Word = word; 
    //     }
    //
    //     return root;
    // }
    //
    // public class TrieNode
    // {
    //     public readonly Dictionary<char, TrieNode> Children = new();
    //     public string? Word;
    // }

    #endregion

    public override void Run()
    {
        char[][] board =
            // [
            //     ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            //     ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            //     ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            //     ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'],
            //     ['b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'], ['a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b']
            // ];
            // [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'], ['i', 'h', 'k', 'r'], ['i', 'f', 'l', 'v']];
            [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'], ['i', 'h', 'k', 'r'], ['i', 'f', 'l', 'v']];
        string[] words =
            // [
            //     "aababababa", "abbabababa", "acbabababa", "adbabababa", "aebabababa", "afbabababa", "agbabababa",
            //     "ahbabababa"
            // ];
            // ["oath", "pea", "eat", "rain", "hklf", "hf"];
            ["oath", "pea", "eat", "rain"];
        Console.WriteLine(JsonSerializer.Serialize(FindWords(board, words)));
    }
}