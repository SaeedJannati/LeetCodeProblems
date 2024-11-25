using System.ComponentModel;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode1268SearchSuggestionsSystem: BaseProblemClass
{
    public IList<IList<string>> SuggestedProducts(string[] products, string searchWord)
    {
        var root = new TrieNode(products);
        string currentSearchWord = string.Empty;
        IList<IList<string>> output = [];
        for (int i = 0,e=searchWord.Length; i < e; i++)
        {
            currentSearchWord += searchWord[i];
            output.Add(SuggestedProducts(root, currentSearchWord));
        }
        return output;
    }

    private IList<string> SuggestedProducts(TrieNode root, string searchWord)
    {
        TrieNode current=root;
        TrieNode node=null;
        for (int i = 0,e=searchWord.Length; i < e; i++)
        {
            if (!current.children.TryGetValue(searchWord[i], out node))
                return [];
            current=node;
        }
        IList<string> output = [];
        Dfs(current, output);
        return output;
    }

    private void Dfs(TrieNode node,IList<string> products)
    {
        if(products.Count>=3)
            return;
        if(node.word!=null)
            products.Add(node.word);
        foreach (var key in node.sortedKeys)
        {
            Dfs(node.children[key.Key],products);
        }
    }

    public class TrieNode
    {
        public TrieNode()
        {
        }

        public TrieNode(string[] words)
        {
            var current = this;
            foreach (var w in words)
            {
                current = this;
                foreach (var @char in w)
                {
                    TrieNode child=null;
                    if (!current.children.TryGetValue(@char, out child))
                    {
                        child = new TrieNode();
                        current.sortedKeys.Add(@char,@char);
                        current.children.Add(@char,child);
                    }
                    current = child;
                }

                current.word = w;
            }
        }

        public SortedList<char, char> sortedKeys = [];
        public string? word;
        public Dictionary<char,TrieNode> children = [];
    }


    public override void Run()
    {
        string[] products = ["mobile", "mouse", "moneypot", "monitor", "mousepad"];
        string word = "mouse";
        Console.WriteLine(JsonSerializer.Serialize(SuggestedProducts(products, word)));
    }
}