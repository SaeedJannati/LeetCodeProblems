namespace LeetCodeProblems.Problems;

public class LeetCode150EvaluateReversePolishNotation
{
    public int EvalRPN(string[] tokens)
    {
        Stack<string> parts = [];
        foreach (var token in tokens)
        {
           parts.Push(token);
        }

        return Calc(parts);
    }

    int Calc(Stack<string> parts)
    {
        var part=parts.Pop();
        int first = 0, second = 0;
        switch (part)
        {
            case "+":
                return Calc(parts) + Calc(parts);
            case "-":
                 first=Calc(parts);
                 second=Calc(parts);
                return second - first;
            case "*":
                return Calc(parts) * Calc(parts);
            case "/":
                first=Calc(parts);
                second=Calc(parts);
                return second / first;
        }

        return int.Parse(part);
    }
}