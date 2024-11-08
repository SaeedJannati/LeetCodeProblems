namespace LeetCodeProblems.Problems;

public class LeetCode139WordBreak : BaseProblemClass
{
    #region Dp Solution

    public bool WordBreak(string s, IList<string> wordDict)
    {
        var length = s.Length;
        List<bool> dp = Enumerable.Range(0, length+1).Select(_ => false).ToList();
        dp[^1] = true;
        string subString = string.Empty;
        for (int i = length - 1; i >= 0; i--)
        {
            subString = s[i..];
            foreach (var str in wordDict)
            {
                if (!subString.StartsWith(str))
                    continue;
                if (i + str.Length == length)
                {
                    dp[i] = true;
                    break;
                }

                dp[i] = dp[i + str.Length];
                if (dp[i] )
                    break;
            }
        }
        return dp[0];
    }

    #endregion

    #region Shitty solution but accepted

    // public bool WordBreak(string s, IList<string> wordDict)
    // {
    //     var trie = new Trie(wordDict);
    //     var wordVector = GetStringVector(s);
    //     if (!trie.CheckCharVector(wordVector))
    //         return false;
    //     var word = s.ToArray().ToList();
    //
    //     return LookForAWord(word, trie).complete;
    // }
    //
    // Dictionary<string, (bool complete, List<List<char>> possibleWord)> memo =
    //     new Dictionary<string, (bool complete, List<List<char>> possibleWord)>();
    //
    // (bool complete, List<List<char>> possibleWord) LookForAWord(List<char> word, Trie trie)
    // {
    //     var wordInString = string.Join("", word);
    //     if (memo.TryGetValue(wordInString, out var aWord))
    //         return aWord;
    //     List<List<char>> result = new();
    //     int length = word.Count;
    //     for (int i = 0; i < length; i++)
    //     {
    //         if (!trie.Contains(word, i, false) && result.Count == 0)
    //         {
    //             memo.TryAdd(wordInString, (false, result));
    //             return (false, result);
    //         }
    //
    //
    //         if (trie.Contains(word, i))
    //         {
    //             if (i == length - 1)
    //             {
    //                 memo.TryAdd(wordInString, (true, result));
    //                 return (true, result);
    //             }
    //
    //
    //             result.Add(word.GetRange(i + 1, length - i - 1));
    //         }
    //     }
    //
    //     foreach (var array in result)
    //     {
    //         if (LookForAWord(array, trie).complete)
    //         {
    //             memo.TryAdd(wordInString, (true, []));
    //             return (true, []);
    //         }
    //     }
    //
    //     memo.TryAdd(wordInString, (false, result));
    //     return (false, result);
    // }
    //
    // HashSet<char> GetStringVector(string word)
    // {
    //     var output = new HashSet<char>(word.Length);
    //     foreach (var c in word)
    //     {
    //         output.Add(c);
    //     }
    //
    //     return output;
    // }
    //
    // public class Trie
    // {
    //     private readonly TrieNode _root = new();
    //     private readonly HashSet<char> charsSet = [];
    //
    //     public Trie()
    //     {
    //     }
    //
    //     public Trie(IEnumerable<string> words)
    //     {
    //         foreach (var word in words)
    //         {
    //             Add(word);
    //         }
    //     }
    //
    //     public bool CheckCharVector(HashSet<char> vector)
    //     {
    //         return vector.Count <= charsSet.Count;
    //     }
    //
    //
    //     public void Add(string word)
    //     {
    //         var current = _root;
    //         foreach (var c in word)
    //         {
    //             charsSet.Add(c);
    //             if (current.Children.TryGetValue(c, out var child))
    //             {
    //                 current = child;
    //                 continue;
    //             }
    //
    //             current.Children[c] = new();
    //             current = current.Children[c];
    //         }
    //
    //         current.IsEndOfWord = true;
    //     }
    //
    //     public bool Contains(List<char> word, int index, bool isEnd = true)
    //     {
    //         var current = _root;
    //         for (int i = 0; i <= index; i++)
    //         {
    //             if (!current.Children.TryGetValue(word[i], out var child))
    //                 return false;
    //             current = child;
    //         }
    //
    //         if (!isEnd)
    //             return true;
    //         return current.IsEndOfWord;
    //     }
    //
    //     public bool Contains(string word, bool isCompleteWord = true)
    //     {
    //         var current = _root;
    //         foreach (var c in word)
    //         {
    //             if (!current.Children.TryGetValue(c, out var child))
    //                 return false;
    //             current = child;
    //         }
    //
    //         if (!isCompleteWord)
    //             return true;
    //         return current.IsEndOfWord;
    //     }
    // }
    //
    // public class TrieNode
    // {
    //     public bool IsEndOfWord { get; set; }
    //     public Dictionary<char, TrieNode> Children { get; } = [];
    // }

    #endregion

    public override void Run()
    {
        string input = "catsandog";
        IList<string> words = ["cats", "dog", "sand", "and", "cat"];
        Console.WriteLine(WordBreak(input, words));
    }
}