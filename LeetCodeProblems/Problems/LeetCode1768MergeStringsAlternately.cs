using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode1768MergeStringsAlternately : BaseProblemClass
{
    public string MergeAlternately(string word1, string word2)
    {
        int fisrtLength = word1.Length;
        int secondLength = word2.Length;
        int maxLength = Math.Max(fisrtLength, secondLength);
        StringBuilder builder = new();
        for (int i = 0; i < maxLength; i++)
        {
            if(i<fisrtLength)
                builder.Append(word1[i]);
            if(i<secondLength)
                builder.Append(word2[i]);
        }

        return builder.ToString();
    }

    public override void Run()
    {
        string fisrtWord = "ab";
        string secondWord = "pqrs";
        Console.WriteLine(MergeAlternately(fisrtWord, secondWord));
    }
}