namespace LeetCodeProblems.Problems;

public class LeetCode242ValidAnagram
{
    public bool IsAnagram(string s, string t)
    {
        var sVector = GetVector(s);
        var tVector = GetVector(t);
        if (sVector.Count != tVector.Count)
            return false;
        foreach (var pair in sVector)
        {
            if (!tVector.TryGetValue(pair.Key, out var val))
                return false;
            if (val != pair.Value)
                return false;
        }

        return true;
    }

    public Dictionary<char, int> GetVector(string str)
    {
        Dictionary<char, int> vector = [];
        foreach (var c in str)
        {
            if(!vector.TryAdd(c, 1))
                vector[c]++;
        }
        return vector;
    }
}