using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode290WordPattern: BaseProblemClass
{
    public bool WordPattern(string pattern, string s)
    {
        List<string> strings = s.Split(' ').ToList();
        strings.ForEach(replace => { replace = replace.Replace(" ", ""); });
        for (int i = strings.Count - 1; i >= 0; i--)
        {
            if (strings[i].Length == 0)
                strings.RemoveAt(i);
        }
        if (strings.Count != pattern.Length)
            return false;
        int length = strings.Count;
        Dictionary<char, string> sPDict = [];
        for (int i = 0; i < length; i++)
        {
            if (sPDict.TryGetValue(pattern[i], out string? value))
            {
                if(value != strings[i])
                    return false;
                continue;
            }
            sPDict[pattern[i]] = strings[i];
        }
        Dictionary<string, char> pSDict = [];
        for (int i = 0; i < length; i++)
        {
            if (pSDict.TryGetValue(strings[i], out var value))
            {
                if(value != pattern[i])
                    return false;
                continue;
            }
            pSDict[strings[i]] =pattern[i] ;
        }

        if (sPDict.Count != pSDict.Count)
            return false;
        foreach (var pair in sPDict)
        {
            if (!pSDict.TryGetValue(pair.Value, out var value))
                return false;
            if (value != pair.Key)
                return false;
        }

        return true;
    }

    public override void Run()
    {
        string s = " a    bb  ccc    dd ee Ff";
        string pattern = " abcdefghijklmnopqrstuvwxyz";
        WordPattern(pattern, s);
    }
}