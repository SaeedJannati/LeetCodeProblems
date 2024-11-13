using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode30SubstringWithConcatenationOfAllWords : BaseProblemClass
{
    public IList<int> FindSubstring(string s, string[] words)
    {
        if (words.Length == 0)
            return [];

        int wordLength = words[0].Length;
        int wordCount = words.Length;
        int length = wordLength * wordCount;
        if (s.Length < length)
            return [];

        var input = s.ToList();
        int lastPossibleStart = input.Count - length;
        var trie = new Trie();
        Dictionary<int, int> wrodsDict = [];
        trie.Add(words, wrodsDict);
        
    
        var dict = GetDictionary(s);
        if (dict.Count == 1 && wrodsDict.Count == 1)
        {
            if (words[0][0] == s[0])
            {
                return Enumerable.Range(0, lastPossibleStart+1).ToList();
            }
        }
        
        IList<int> output = [];
        int wordIndex = -1;
        Dictionary<int, int> wordsSoFar = [];
        for (int i = 0; i <= lastPossibleStart; i++)
        {
            wordsSoFar = new(wordCount);
            for (int j = 0; j < wordCount; j++)
            {
                if (!trie.HasWord(input.GetRange(i + j * wordLength, wordLength), out wordIndex))
                {
                    break;
                }

                if (!wordsSoFar.TryAdd(wordIndex, 1))
                {
                    wordsSoFar[wordIndex]++;
                }

                if (wordsSoFar[wordIndex] > wrodsDict[wordIndex])
                {
                    break;
                }
            }

            if (AreSame(wrodsDict, wordsSoFar))
                output.Add(i);
        }

        return output;
    }

    private bool AreSame(Dictionary<int, int> dict1, Dictionary<int, int> dict2)
    {
        if (dict1.Count != dict2.Count)
            return false;
        foreach (var pair in dict1)
        {
            if (!dict2.TryGetValue(pair.Key, out var value))
                return false;
            if (value != pair.Value)
                return false;
        }

        return true;
    }

    public class Trie
    {
        private Node _root = new();

        public Trie()
        {
        }


        public void Add(string[] words, Dictionary<int, int> wordDict)
        {
            int index = 0;
            for (int i = words.Length - 1; i >= 0; i--)
            {
                index = i;
                if (Add(words[i], ref index))
                {
                    wordDict[index] = 1;
                    continue;
                }

                wordDict[index]++;
            }
        }

        public bool Add(string word, ref int index)
        {
            var currentNode = _root;
            Node? node;
            foreach (var c in word)
            {
                if (!currentNode.Children.TryGetValue(c, out node))
                {
                    node = new Node();
                    currentNode.Children.Add(c, node);
                }

                currentNode = node;
            }

            if (currentNode.IsEndOfWord)
            {
                index = currentNode.wordIndex;
                return false;
            }

            currentNode.IsEndOfWord = true;
            currentNode.wordIndex = index;
            return true;
        }

        public bool HasWord(List<char> word, out int index)
        {
            var currentNode = _root;
            foreach (var c in word)
            {
                if (!currentNode.Children.TryGetValue(c, out currentNode))
                {
                    index = -1;
                    return false;
                }
            }

            index = currentNode.wordIndex;
            return currentNode.IsEndOfWord;
        }

        public class Node
        {
            public Dictionary<char, Node> Children = [];
            public bool IsEndOfWord = false;
            public int wordIndex = -1;
        }
    }

    Dictionary<char, int> GetDictionary(string word)
    {
        Dictionary<char,int> dict = new();
        foreach (var c in word.Where(c => !dict.TryAdd(c, 1)))
        {
            dict[c] ++;
        }
        return dict;    
    }

    public override void Run()
    {
        var input = "wordgoodgoodgoodbestword";
        string[] words = ["word", "good", "best", "good"];
        Console.WriteLine(JsonSerializer.Serialize(FindSubstring(input, words)));
    }
}