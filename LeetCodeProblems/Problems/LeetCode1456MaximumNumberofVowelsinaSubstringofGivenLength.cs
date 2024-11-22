namespace LeetCodeProblems.Problems;

public class LeetCode1456MaximumNumberofVowelsinaSubstringofGivenLength
{
    public int MaxVowels(string s, int k)
    {
        if (s == null || s.Length == 0)
            return 0;
        int maxVowels = 0;
        int currentVowels = 0;
        int length = s.Length;
        int top = Math.Min(length, k);
        for (int i = 0; i < top; i++)
        {
            if(IsVowel(s[i]))
                maxVowels++;
        }
        if(k>=length)
            return maxVowels;
        currentVowels = maxVowels;
        for (int i = top ; i < length; i++)
        {
            if(IsVowel(s[i-k]))
                currentVowels--;
            if(IsVowel(s[i]))
                currentVowels++;
            if(currentVowels>maxVowels)
                maxVowels = currentVowels;
        }

        return maxVowels;
    }

    private bool IsVowel(char c)
    {
        return c is 'a' or 'e' or 'i' or 'o' or 'u';
    }

}