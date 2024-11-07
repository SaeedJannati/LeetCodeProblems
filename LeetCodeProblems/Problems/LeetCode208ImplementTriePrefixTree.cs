namespace LeetCodeProblems.Problems;

public class LeetCode208ImplementTriePrefixTree: BaseProblemClass
{
    public class Trie
    {
        TrieNode root;

        public Trie()
        {
            root = new();
        }

        public void Insert(string word)
        {
            var current = root;
            TrieNode newNode = new();
            foreach (var c in word)
            {
                if (current.Children.ContainsKey(c))
                {
                    current = current.Children[c];
                    continue;
                }

                newNode = new TrieNode();
                current.Children.Add(c, newNode);
                current=current.Children[c];
            }

            current.IsEndOfTerm = true;
        }

        public bool Search(string word)
        {
            var current = root;
            foreach (var c in word)
            {
                if (!current.Children.ContainsKey(c))
                    return false;
                current = current.Children[c];
            }

            return current.IsEndOfTerm;
        }

        public bool StartsWith(string prefix)
        {
            var current = root;
            foreach (var c in prefix)
            {
                if (!current.Children.ContainsKey(c))
                    return false;
                current = current.Children[c];
            }

            return true;
        }
    }

    public class TrieNode
    {
        public Dictionary<char, TrieNode> Children = [];
        public bool IsEndOfTerm = false;
    }

    public override void Run()
    {
        var trie = new Trie();
        trie.Insert("apple");
        Console.WriteLine(trie.Search("apple"));
    }
}