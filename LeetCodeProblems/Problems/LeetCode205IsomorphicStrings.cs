namespace LeetCodeProblems.Problems;

public class LeetCode205IsomorphicStrings
{
    public bool IsIsomorphic(string s, string t)
    {
        if (s.Length != t.Length)
            return false;
        var st = CreateMap(s, t);
        if (!st.possible)
            return false;
        var stMap = st.dict;
        var ts=CreateMap(t, s);
        if (!ts.possible)
            return false;
        var tsMap = ts.dict;
        if (stMap.Count != tsMap.Count)
            return false;
        foreach (var pair in stMap)
        {
            if (!tsMap.TryGetValue(pair.Value, out var res))
                return false;
            if (res != pair.Key)
                return false;
        }

        return true;
    }

    (Dictionary<char, char> dict,bool possible) CreateMap(string s, string t)
    {
        Dictionary<char, char> map =[];
        for (int i = 0,e=s.Length; i < e; i++)
        {
            if (map.TryGetValue(s[i], out var c))
            {
                if(c==t[i])
                    continue;
                return ([], false);
            }

            map[s[i]] = t[i];
        }

        return (map,true);
    }
}