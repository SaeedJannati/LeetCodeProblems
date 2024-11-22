namespace LeetCodeProblems.Problems;

public class LeetCode2390RemovingStarsFromaString
{
    public string RemoveStars(string s)
    {
        if (s == null || s.Length == 0)
            return s;
        Stack<char> stack = [];
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == '*')
            {
                stack.Pop();
                continue;
            }

            stack.Push(s[i]);
        }
        List<char> result = new List<char>(stack.Count);
        while (stack.Count>0)
        {
            result.Add(stack.Pop());
        }
        result.Reverse();
        return  new string(result.ToArray());
    }
}