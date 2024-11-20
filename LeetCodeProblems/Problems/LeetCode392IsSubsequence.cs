namespace LeetCodeProblems.Problems;

public class LeetCode392IsSubsequence
{
    public bool IsSubsequence(string s, string t)
    {
        if (t.Length < s.Length)
            return false;
        if (t == s)
            return true;
        Dictionary<char, PriorityQueue<int, int>> map = new(t.Length);
        for (int i = 0, e = t.Length; i < e; i++)
        {
            if(!map.ContainsKey(t[i]))
                map[t[i]] = new PriorityQueue<int, int>();
            map[t[i]].Enqueue(i,i);
        }

        int lastPos = -1;
        int pos = 0;
        for (int i = 0, e = s.Length; i < e; i++)
        {
            if (!map.TryGetValue(s[i], out var value))
                return false;
            pos=lastPos - 1;
            while (value.Count>0&& pos<=lastPos)
            {
                pos= value.Dequeue();    
            }
            if(pos<=lastPos)
                return false;
            if (map[s[i]].Count == 0)
                map.Remove(s[i]);
            lastPos = pos;
        }

        return true;
    }
}