namespace LeetCodeProblems.Problems;

public class LeetCode125ValidPalindrome : BaseProblemClass
{
    private static readonly Lazy<HashSet<char>> charSet = new(() =>
        Enumerable.Range('a', 26).Select(c => (char) c)
            .Concat(Enumerable.Range('0', 10).Select(c => (char) c)).ToHashSet());

    public bool IsPalindrome(string s)
    {
        s = s.Replace(" ", "");
        s = s.ToLower();
        if (s.Length == 0)
            return true;
        int length = s.Length - 1;
        int firstPointer = 0;
        int secondPointer = length;
        while (secondPointer >= firstPointer)
        {
            while (!charSet.Value.Contains(s[firstPointer]) && firstPointer < secondPointer)
            {
                firstPointer++;
                if (firstPointer > length)
                    return true;
            }

            while (!charSet.Value.Contains(s[secondPointer]) && firstPointer < secondPointer)
            {
                secondPointer--;
                if (secondPointer < 0)
                    return true;
            }

            if (firstPointer == secondPointer)
                break;
            if (s[firstPointer] != s[secondPointer])
                return false;
            firstPointer++;
            secondPointer--;
        }

        return true;
    }

    public override void Run()
    {
        var input = ".";
        Console.WriteLine(IsPalindrome(input));
    }
}