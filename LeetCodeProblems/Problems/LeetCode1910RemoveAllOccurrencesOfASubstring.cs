using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode1910RemoveAllOccurrencesOfASubstring : BaseProblemClass
{
    public string RemoveOccurrences(string s, string part)
    {
        Stack<char> stack = [];
        int partLength = part.Length;
        int sLength = s.Length;
        bool matchFound = false;
        foreach (var c in s)
        {
            stack.Push(c);
            if (stack.Count < partLength)
                continue;
            matchFound = true;
            for (int i = 0; i < partLength; i++)
            {
                if (stack.ElementAt(i) != part[^(i + 1)])
                {
                    matchFound = false;
                    break;
                }
                
            }

            if (matchFound)
            {
                for (int i = 0; i < partLength; i++)
                    stack.Pop();
            }
        }

        return new string(stack.Reverse().ToArray());
    }

    public override void Run()
    {
        string s =
            // "gjzgbpggjzgbpgsvpwdk";
            // "axxxxyyyyb"; 
            "oyvkybghubuasnqecycougyyqyoigvsdtoxzuhczadmeljqjevpoyvkybghuboyvkybghubuasnqecycougyyqyoigvsdtoxzuhczadmeljqjevppzrhnquasnqecycougyyqyoigvsdtoxzuhczadmeljqjevppzrhnqpzrhnqmezykrswjo";
            string part =
                // "gjzgbpg";
                // "xy";
            "oyvkybghubuasnqecycougyyqyoigvsdtoxzuhczadmeljqjevppzrhnq";
        Console.WriteLine(RemoveOccurrences(s, part));
    }
}