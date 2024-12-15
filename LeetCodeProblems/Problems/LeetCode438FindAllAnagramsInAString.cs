namespace LeetCodeProblems.Problems;

public class LeetCode438FindAllAnagramsInAString
{
    public IList<int> FindAnagrams(string s, string p)
    {
        int pLength = p.Length;
        int sLength = s.Length;
        if (pLength > sLength)
            return [];
        var pMap = CalculateHashMap(p);
        IList<int> outPut = [];
        Dictionary<char, int> currentMap = [];
        for (int i = 0; i < pLength; i++)
        {
            AddChar(currentMap,s[i]);
        }
        if(CheckEquality(currentMap, pMap))
            outPut.Add(0);
        for (int i = pLength; i < sLength; i++)
        {
            RemoveChar(currentMap,s[i-pLength]);
            AddChar(currentMap,s[i]);
            if(CheckEquality(currentMap, pMap))
                outPut.Add(i-pLength+1);
        }
        return outPut;
    }

    private void AddChar(Dictionary<char, int> map, char ch)
    {
        if(!map.TryAdd(ch,1))
            map[ch]++;
    }

    private void RemoveChar(Dictionary<char, int> map, char ch)
    {
        map[ch]--;
        if (map[ch] == 0)
            map.Remove(ch);
    }

    private bool CheckEquality(Dictionary<char, int> dict1, Dictionary<char, int> dict2)
    {
        if (dict1.Count != dict2.Count)
            return false;
        foreach (var pair in dict1)
        {
            if(!dict2.TryGetValue(pair.Key, out var value))
                return false;
            if (value!=pair.Value)
            {
                return false;
            }
        }

        return true;
    }

    private Dictionary<char, int> CalculateHashMap(string s)
    {
        Dictionary<char, int> map = [];
        foreach (var c in s.Where(c => !map.TryAdd(c, 1)))
        {
            map[c]++;
        }

        return map;
    }
}