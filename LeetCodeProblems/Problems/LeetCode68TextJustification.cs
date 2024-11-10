using System.Text;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode68TextJustification : BaseProblemClass
{
    public IList<string> FullJustify(string[] words, int maxWidth)
    {
        var result = new List<string>();
        var wordsInCurrentLine = new List<string>();
        int currentLineWidth = 0;
        for (int i = 0, e = words.Length; i < e; i++)
        {
            if (currentLineWidth + words[i].Length + wordsInCurrentLine.Count <= maxWidth)
            {
                wordsInCurrentLine.Add(words[i]);
                currentLineWidth += words[i].Length;
                continue;
            }

            result.Add(CreateLine(wordsInCurrentLine, maxWidth));
            wordsInCurrentLine = [words[i]];
            currentLineWidth=words[i].Length;
        }

        result.Add(CreateLine(wordsInCurrentLine, maxWidth,true));
        return result;
    }

    private string CreateLine(List<string> words, int lineLength, bool isLastLine = false)
    {
        var builder = new StringBuilder();
        var endSpaces = 0;
        if (words.Count == 1)
        {
            builder.Append(words[0]);
            endSpaces = lineLength - builder.Length;
            builder.Append(string.Concat(Enumerable.Repeat(' ', endSpaces)));
            return builder.ToString();
        }

        if (isLastLine)
        {
            builder.Append(string.Join(' ', words));
            endSpaces = lineLength - builder.Length;
            builder.Append(string.Concat(Enumerable.Repeat(' ', endSpaces)));
            return builder.ToString();
        }

        var totalWordLength = words.Sum(i => i.Length);
        var spacesInBetween = lineLength - totalWordLength;
        var remain = spacesInBetween % (words.Count - 1);
        var baseSpace = spacesInBetween / (words.Count - 1);
        var baseSpaceStr = string.Concat(Enumerable.Repeat(' ', baseSpace));
        if (remain == 0)
        {
            builder.Append(string.Join(baseSpaceStr, words));
            return builder.ToString();
        }

        var leftSpaceStr = string.Concat(Enumerable.Repeat(' ', baseSpace + 1));
        builder.Append(string.Join(leftSpaceStr, words.GetRange(0, remain)));
        builder.Append(leftSpaceStr);
        builder.Append(string.Join(baseSpaceStr, words.GetRange(remain, words.Count - remain)));

        return builder.ToString();
    }

    public override void Run()
    {
        string[] words = ["What","must","be","acknowledgment","shall","be"];
        int maxLength = 16;
        Console.WriteLine(JsonSerializer.Serialize(FullJustify(words, maxLength)));
    }
}