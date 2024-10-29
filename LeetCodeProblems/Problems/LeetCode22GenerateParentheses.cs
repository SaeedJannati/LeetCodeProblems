using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode22GenerateParentheses : BaseProblemClass
{
    private List<char> parentheses = ['(', ')'];

    public IList<string> GenerateParenthesis(int n)
    {
        IList<string> outPut = [];
        for (int i = 0, e = 2 * n; i < e; i++)
        {
            AddLayer(outPut, n, i == e - 1);
        }

        return outPut;
    }

    private void AddLayer(IList<string> outPut, int n, bool complete)
    {
        if (outPut.Count == 0)
        {
            outPut.Add("(");
        }

        bool addedAny = false;
        for (int i = outPut.Count - 1; i >= 0; i--)
        {
            addedAny = false;
            var temp = outPut[i];
            foreach (var c in parentheses)
            {
                if (!IsValid(temp + c, n, complete))
                    continue;
                if (!addedAny)
                {
                    addedAny = true;
                    outPut[i] += c;
                    continue;
                }

                outPut.Add(temp + c);
            }
        }
    }

    private bool IsValid(string input, int n, bool completeTerm)
    {
        int openParanthesisTotal = 0;
        int openedParenthesisNet = 0;
        foreach (var c in input)
        {
            if (c == '(')
            {
                openedParenthesisNet++;
                openParanthesisTotal++;
                if (openParanthesisTotal > n)
                    return false;
            }
            else
            {
                openedParenthesisNet--;
            }

            if (openedParenthesisNet < 0)
                return false;
        }

        if (!completeTerm)
            return true;
        return openedParenthesisNet == 0;
    }

    public override void Run()
    {
        int n = 5;
        Console.WriteLine(JsonSerializer.Serialize(GenerateParenthesis(n)));
    }
}