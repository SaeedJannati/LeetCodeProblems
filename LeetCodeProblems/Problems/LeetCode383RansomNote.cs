namespace LeetCodeProblems.Problems;

public class LeetCode383RansomNote
{
    public bool CanConstruct(string ransomNote, string magazine)
    {
        return ContainVector(CreateVector(magazine), CreateVector(ransomNote));
    }

    private bool ContainVector(Dictionary<char, int> container, Dictionary<char, int> target)
    {
        if (container.Count < target.Count)
            return false;
        foreach (var pair in target)
        {
            if (!container.ContainsKey(pair.Key))
                return false;
            if (container[pair.Key] < pair.Value)
                return false;
        }

        return true;
    }

    private Dictionary<char, int> CreateVector(string someString)
    {
        Dictionary<char, int> vector = new (someString.Length);
        foreach (var c in someString)
        {
         if(vector.ContainsKey(c))
             vector[c]++;
         else
             vector.Add(c, 1);
        }

        return vector;
    }
}