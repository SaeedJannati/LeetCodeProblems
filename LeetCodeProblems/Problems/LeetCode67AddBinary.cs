using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode67AddBinary : BaseProblemClass
{
    public string AddBinary(string a, string b)
    {
        Stack<char> output = new();
        int lengthA = a.Length;
        int lengthB = b.Length;
        int length = int.Max(lengthA, lengthB);
        char remainder = '0';
        char aChar;
        char bChar;
        for (int i = 0; i < length; i++)
        {
            aChar = '0';
            bChar = '0';
            if (i < lengthA)
                aChar = a[^(1 + i)];
            if (i < lengthB)
                bChar = b[^(1 + i)];
            output.Push(Sum(aChar, bChar, ref remainder));
        }

        if (remainder == '1')
            output.Push('1');
        return string.Join("", output.ToArray());
    }

    char Sum(char a, char b, ref char remainder)
    {
        int aInt = a == '0' ? 0 : 1;
        int bInt = b == '0' ? 0 : 1;
        int remainderInt = remainder == '0' ? 0 : 1;
        int outputInt = aInt + bInt + remainderInt;
        switch (outputInt)
        {
            case 0:
                remainder = '0';
                return '0';
            case 1:
                remainder = '0';
                return '1';
            case 2:
                remainder = '1';
                return '0';
            case 3:
                remainder = '1';
                return '1';
            default:
                return '0';
        }
    }

    public override void Run()
    {
        string a = "1";
        string b = "11";
        Console.WriteLine(AddBinary(a, b));
    }
}