namespace LeetCodeProblems.Problems;

public class LeetCode345ReverseVowelsofaString
{
    public string ReverseVowels(string s)
    {
        List<(int index, char character) > vowels = [];
        int length = s.Length;
        var chars = s.ToCharArray();
        for (int i = 0; i < length; i++)
        {
            if (!IsVowel(s[i]))
                continue;
            vowels.Add((i, s[i]));
        }

        var vowelsCount = vowels.Count;
        for (int j = 0, e = vowelsCount / 2; j < e; j++)
        {
            chars[vowels[j].index] =vowels[vowelsCount-j - 1].character;
            chars[vowels[vowelsCount - j - 1].index] = vowels[j].character;
        }
        return new string(chars);
    }

    private bool IsVowel(char @char)
    {
        @char = char.ToLower(@char);
        return @char is 'a' or 'e' or 'i' or 'o' or 'u';
    }
}