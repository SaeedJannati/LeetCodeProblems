using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode151ReverseWordsInAString: BaseProblemClass
{
    public string ReverseWords(string s)
    {
        var words = s.Split(' ').ToList();
        var builder = new StringBuilder();
        for (int i = words.Count - 1; i >= 0; i--)
        {
            if (string.IsNullOrWhiteSpace(words[i]))
                words.RemoveAt(i);
            else
            {
                words[i] = words[i].Replace(" ", ""); 
                words[i] += " ";
                builder.Append(words[i]);
            }
        }
        builder.Remove(builder.Length - 1, 1);
        return builder.ToString();
    }

    public override void Run()
    {
        string input = "  hello world  ";
        Console.WriteLine(ReverseWords(input));
    }
}