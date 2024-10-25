namespace LeetCodeProblems.Problems;

public class LeetCode49GroupAnagrams : BaseProblemClass
{
    public override void Run()
    {
    }

    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        Dictionary<Dictionary<char, int>, Queue<string>> dict = [];
        foreach (var str in strs)
        {
            var vector = GetVector(str);
            bool foundPlace = false;
            foreach (var pair in dict)
            {
                if (AreAnagrams(vector, pair.Key))
                {
                    pair.Value.Enqueue(str);
                    foundPlace = true;
                    break;
                }
            }

            if (!foundPlace)
            {
                dict[vector] = new Queue<string>();
                dict[vector].Enqueue(str);
            }
            
        }

        return dict.Values.Select(queue => queue.ToList()).Cast<IList<string>>().ToList();
    }

    private bool AreAnagrams(Dictionary<char, int> dic1, Dictionary<char, int> dic2)
    {
        if (dic1.Count != dic2.Count)
            return false;
        foreach (var pair in dic1)
        {
            if (!dic2.TryGetValue(pair.Key, out var value))
                return false;
            if (value != pair.Value)
                return false;
        }

        return true;
    }

    private Dictionary<char, int> GetVector(string word)
    {
        Dictionary<char, int> vector = [];
        foreach (char c in word)
        {
            if (vector.ContainsKey(c))
            {
                vector[c]++;
                continue;
            }

            vector[c] = 1;
        }

        return vector;
    }
}