namespace LeetCodeProblems.Models;

public class Trie
{
    private readonly TrieNode _root=new ();
    public void Insert(string word)
    {
        var current = _root;
        TrieNode newNode = new();
        foreach (var c in word)
        {
            if (current.Children.TryGetValue(c, out var child))
            {
                current = child;
                continue;
            }

            newNode = new TrieNode();
            current.Children.Add(c, newNode);
            current = current.Children[c];
        }

        current.IsEndOfTerm = true;
    }

    public bool Search(string word)
    {
        var current = _root;
        foreach (var c in word)
        {
            if (!current.Children.TryGetValue(c, value: out var child))
                return false;
            current = child;
        }

        return current.IsEndOfTerm;
    }

    public bool StartsWith(string prefix)
    {
        var current = _root;
        foreach (var c in prefix)
        {
            if (!current.Children.TryGetValue(c, out var value))
                return false;
            current = value;
        }

        return true;
    }


    public class TrieNode
    {
        public  Dictionary<char, TrieNode> Children { get; } = [];
        public bool IsEndOfTerm { get; set; }
    }
}