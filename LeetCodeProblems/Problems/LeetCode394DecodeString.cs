using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode394DecodeString : BaseProblemClass
{
    public string DecodeString(string s)
    {
        return Decode(s);
    }

    private string Decode(string str)
    {
        StringBuilder builder = new StringBuilder();
        int bracketCount = 0;
        Stack<char> numStack = [];
        int power = 0;
        int multiplier = 0;
        List<char> chars = [];
        multiplier = 0;
        for (int i = 0, e = str.Length; i < e; i++)
        {
            while (multiplier == 0 && str[i] >= '0' && str[i] <= '9')
            {
                numStack.Push(str[i]);
                i++;
            }

            power = 1;
            while (numStack.Count > 0)
            {
                multiplier += int.Parse(numStack.Pop().ToString()) * power;
                power *= 10;
            }

            if (bracketCount > 0)
                chars.Add(str[i]);
            if (str[i] == '[')
            {
                bracketCount++;
            }

            if (str[i] == ']')
                bracketCount--;
            if (bracketCount == 0)
            {
                if (multiplier > 0)
                {
                    var part = Decode(new string(chars.ToArray()));
                    for (int j = 0; j < multiplier; j++)
                    {
                        builder.Append(part);
                    }

                    multiplier = 0;
                    chars = [];
                    continue;
                }

                builder.Append(str[i]);
            }
        }

        return builder.ToString();
    }

    public override void Run()
    {
        var output = DecodeString("3[a2[c]]");
        Console.WriteLine(output);
    }
}