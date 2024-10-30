namespace LeetCodeProblems.Problems;

public class LeetCode76MinimumWindowSubstring: BaseProblemClass
{
    public string MinWindow(string s, string t)
    {
        if (t.Length > s.Length)
            return string.Empty;
        var targetDict = CreateVector(t);
        Dictionary<char, int> currentWindow = [];
        int firstIndex = 0;
        int minFirstIndex = 0;
        int length = 0;
        int minLength = s.Length;
        for (int i = 0, e = s.Length; i < e; i++)
        {
            AddChar(currentWindow, s[i]);
            if (!DoesContainWord(currentWindow, targetDict))
                continue;
            for (int j = firstIndex; j < i; j++)
            {
                if(!TryRemoveChar(currentWindow, targetDict, s[j]))
                    break;
                firstIndex ++;
            }
            length=i-firstIndex+1;
            if (length < minLength)
            {
                minLength = length;
                minFirstIndex = firstIndex;
            }
        }
        
        if(!DoesContainWord(currentWindow, targetDict))
            return string.Empty;
        return s.Substring(minFirstIndex, minLength);
    }

    private bool TryRemoveChar(Dictionary<char, int> currentWindow, Dictionary<char, int> target, char c)
    {
        if (!target.ContainsKey(c))
        {
            currentWindow[c]--;
            return true;
        }

        if (target[c] >= currentWindow[c])
            return false;
        currentWindow[c]--;
        return true;
    }


    private void AddChar(Dictionary<char, int> dict, char c)
    {
        if (dict.TryAdd(c, 1))
            return;
        dict[c]++;
    }

    private bool DoesContainWord(Dictionary<char, int> input, Dictionary<char, int> target)
    {
        if (input.Count < target.Count)
            return false;
        foreach (var pair in target)
        {
            if (!input.ContainsKey(pair.Key))
                return false;
            if (input[pair.Key] < pair.Value)
                return false;
        }

        return true;
    }

    private Dictionary<char, int> CreateVector(string t)
    {
        Dictionary<char, int> dict = [];
        foreach (var c in t)
        {
            if (dict.ContainsKey(c))
            {
                dict[c]++;
                continue;
            }

            dict[c] = 1;
        }

        return dict;
    }

    public override void Run()
    {
        var input = "a";
        var target = "a";
        Console.WriteLine(MinWindow(input, target));
    }
}