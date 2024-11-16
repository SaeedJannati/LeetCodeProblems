namespace LeetCodeProblems.Problems;

public class LeetCode211DesignAddAndSearchWordsDataStructure: BaseProblemClass
{
    public class WordDictionary
    {
        TrieNode root = new TrieNode();

        public WordDictionary()
        {
        }

        public void AddWord(string word)
        {
            var current = root;
            TrieNode node;
            foreach (var c in word)
            {
                if (!current.Children.TryGetValue(c, out node))
                {
                    node = new TrieNode();
                    current.Children.Add(c, node);
                }

                current = node;
            }

            current.Word = word;
        }

        public bool Search(string word)
        {
            Queue<TrieNode> currentLayer = new Queue<TrieNode>();
            currentLayer.Enqueue(root);
            Queue<TrieNode> nextLayer = new Queue<TrieNode>();
            TrieNode node;
            foreach (var c in word)
            {
                if (c == '.')
                {
                    while (currentLayer.Count > 0)
                    {
                        node = currentLayer.Dequeue();
                        foreach (var n in node.Children)
                        {
                            nextLayer.Enqueue(n.Value);
                        }
                    }
                }
                else
                {
                    while ( currentLayer.Count > 0)
                    {
                        node = currentLayer.Dequeue();
                        if (!node.Children.TryGetValue(c, out var child))
                            continue;
                        nextLayer.Enqueue(child);
                    }
                }

                if (nextLayer.Count == 0)
                    return false;
                currentLayer.Clear();
                while (nextLayer.Count>0)
                {
                    currentLayer.Enqueue(nextLayer.Dequeue());
                }
            }

            while (currentLayer.Count > 0)
            {
                node = currentLayer.Dequeue();
                if (node.Word != null)
                    return true;
            }

            return false;
        }

        public class TrieNode
        {
            public Dictionary<char, TrieNode> Children = [];
            public string? Word;
        }
    }

    public override void Run()
    {
        List<string> inputs = ["bad", "dad", "mad", "pad", "bad", ".ad", "b.."];
        var dict = new WordDictionary();
        bool found = false;
        dict.AddWord(inputs[0]);
        dict.AddWord(inputs[1]);
        dict.AddWord(inputs[2]);
        found = dict.Search(inputs[3]);
        found = dict.Search(inputs[4]);
        found = dict.Search(inputs[5]);
        found = dict.Search(inputs[6]);
        
    }
}