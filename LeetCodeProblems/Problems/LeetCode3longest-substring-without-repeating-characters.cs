namespace LeetCodeProblems.Problems;

public class LeetCode3LongestSubstringWithoutRepeatingCharacters : BaseProblemClass
{
    public override void Run()
    {
        var input = "";
        var outPut = LengthOfLongestSubstring(input);
        Console.WriteLine(outPut);
    }

    public int LengthOfLongestSubstring(string s)
    {
        
        var currentChars = new HashSet<char>(24);
        var length = s.Length;
        if (length == 0)
            return 0;
        var firstPointer = 0;
        var secondPointer = 1;
        var maxLength =length>0? 1:0;
        currentChars.Add(s[0]);
        while (secondPointer<length)
        {
            if (currentChars.Contains(s[secondPointer]))
            {
                currentChars.Remove(s[firstPointer]);
                firstPointer++;
                continue;
            }

            currentChars.Add(s[secondPointer]);
            if (currentChars.Count > maxLength)
                maxLength = currentChars.Count;
            secondPointer++;

        }
        return maxLength;
    }
}