namespace LeetCodeProblems.Problems;

public class LeetCode1657DetermineifTwoStringsAreClose
{
    public bool CloseStrings(string word1, string word2)
    {
        if (word1.Length != word2.Length) return false;
        var firstResult = GetSortedList(word1);
        var secondResult = GetSortedList(word2);
        var firstSet = firstResult.set;
        var secondSet = secondResult.set;
        if(firstSet.Count != secondSet.Count) return false;
        if (firstSet.Any(@char => !secondSet.Contains(@char)))
        {
            return false;
        }

        var firstQueue=firstResult.queue;
        var secondQueue=secondResult.queue;
        if (firstQueue.Count != secondQueue.Count) return false;
        while (firstQueue.Count>0)
        {
            if(firstQueue.Dequeue()!=secondQueue.Dequeue())
                return false;
        }

        return true;
    }

    (PriorityQueue<int, int> queue,HashSet<char> set) GetSortedList(string word)
    {
        Dictionary<char, int> dict = [];
        HashSet<char> chars = [];
        foreach (var c in word)
        {
            if (dict.TryAdd(c, 1))
            {
                chars.Add(c);
                continue;
            }

            dict[c]++;
        }

        PriorityQueue<int, int> result = new();
        foreach (var pair in dict)
        {
            result.Enqueue(pair.Value, pair.Value);
        }
        return (result,chars);
    }
}