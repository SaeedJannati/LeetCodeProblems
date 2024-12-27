using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode224BasicCalculator : BaseProblemClass
{
    public override void Run()
    {
        var input = "- (3 + (4 + 5))";
        var outPut = Calculate(input);
        Console.WriteLine(outPut);
    }

    public int Calculate(string s)
    {
        var input = s.Replace(" ", "");
        return CalculateSubstring(input, 1).result;
    }

    private (int result, int length) CalculateSubstring(string input, int generalSign)
    {
        int length = 0;
        int result = 0;
        int sign = 1;
        var builder = new StringBuilder();
        
        for (int i = 0, e = input.Length; i < e; i++)
        {
            length = i+1;
            if (input[i] == ')')
                break;

            if (input[i] == '(')
            {
                var calculationResult = CalculateSubstring(input[(i+1)..], sign);
                result += calculationResult.result;
                i += calculationResult.length;
                builder.Clear();
                continue;
            }

            if (input[i] is '+' or '-')
            {
                if (builder.Length != 0)
                    result += sign * int.Parse(builder.ToString());
                builder.Clear();
                sign = input[i] == '+' ? 1 : -1;
                continue;
            }

            builder.Append(input[i]);
        }

        if (builder.Length != 0)
            result += sign * int.Parse(builder.ToString());
        return (result*generalSign, length);
    }
}

class  GptSolution
{
    public int Calculate(string s)
    {
        return CalculateSubstring(s.Replace(" ", ""), 0, 1).result;
    }

    private (int result, int index) CalculateSubstring(string input, int startIndex, int generalSign)
    {
        int result = 0;
        int sign = 1;
        int num = 0;
        bool hasNumber = false;

        for (var i = startIndex; i < input.Length; i++)
        {
            var current = input[i];

            if (char.IsDigit(current))
            {
                num = num * 10 + (current - '0');
                hasNumber = true;
            }
            else switch (current)
            {
                case '(':
                {
                    var subResult = CalculateSubstring(input, i + 1, sign);
                    result += subResult.result;
                    i = subResult.index;
                    num = 0;
                    hasNumber = false;
                    break;
                }
                case ')':
                {
                    if (hasNumber)
                        result += sign * num;
                    return (result * generalSign, i);
                }
                case '+':
                case '-':
                {
                    if (hasNumber)
                    {
                        result += sign * num;
                        num = 0;
                        hasNumber = false;
                    }
                    sign = (current == '+') ? 1 : -1;
                    break;
                }
            }
        }
        if (hasNumber)
            result += sign * num;

        return (result * generalSign, input.Length);
    }
}