using System.Runtime.InteropServices;
using System.Text;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode5LongestPalindromicSubstring : BaseProblemClass
{
    public override void Run()
    {
        var input = "ac";
        var outPut = LongestPalindrome(input);
        Console.WriteLine(outPut);
    }

    public string LongestPalindrome(string s)
    {
        return CalcWithDynamicProgramming(s);
    }

    private string CalcWithDynamicProgramming(string s)
    {
        if (s.Length <= 1)
            return s;
        var length = s.Length;
        var dpMatrix = new bool[length, length];
        var currentIndex = 0;
        var currentLength = 0;
        var isMatch = false;
        for (int i = length - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                if (length - i == 1)
                {
                    isMatch = true;
                    dpMatrix[j, j + (length - 1 - i)] = isMatch;
                }
                else if (length - i == 2)
                {
                    isMatch = s[j] == s[j + (length - 1 - i)];
                    dpMatrix[j, j + (length - 1 - i)] = isMatch;
                }
                else
                {
                    isMatch = dpMatrix[j + 1, j + (length - 1 - i) - 1] && s[j] == s[j + (length - 1 - i)];
                    dpMatrix[j, j + (length - 1 - i)] = isMatch;
                }

                if (length - i > currentLength && isMatch)
                {
                    currentIndex = j;
                    currentLength = length - i;
                }
            }
        }

        return s.Substring(currentIndex, currentLength);
    }

    private string PrintMatrix<T>(T[,] matirx)
    {
        var outPut = new StringBuilder();
        for (int i = 0; i < matirx.GetLength(0); i++)
        {
            for (int j = 0; j < matirx.GetLength(1); j++)
            {
                outPut.Append($"{matirx[i, j]},");
            }

            outPut.Append('\n');
        }

        return outPut.ToString();
    }

    private string CalcStartFromMiddle(string s)
    {
        if (s.Length <= 1)
            return s;
        var indexOdd = 0;
        var lengthOdd = 1;
        var distance = 0;
        for (int i = 0, e = s.Length; i < e; i++)
        {
            distance = 1;
            while (i - distance >= 0 && i + distance < e)
            {
                if (s[i - distance] != s[i + distance])
                {
                    if (lengthOdd < (distance - 1) * 2 + 1)
                    {
                        lengthOdd = (distance - 1) * 2 + 1;
                        indexOdd = i;
                    }

                    break;
                }

                distance++;
                if (lengthOdd < (distance - 1) * 2 + 1)
                {
                    lengthOdd = (distance - 1) * 2 + 1;
                    indexOdd = i;
                }
            }
        }

        var indexEven = 0;
        var lengthEven = 0;
        for (int i = 0, e = s.Length; i < e; i++)
        {
            distance = 0;
            while (i - distance >= 0 && i + distance + 1 < e)
            {
                if (s[i - distance] != s[i + distance + 1])
                {
                    if (lengthEven < 2 * distance)
                    {
                        lengthEven = 2 * distance;
                        indexEven = i;
                    }

                    break;
                }

                distance++;
                if (lengthEven < 2 * distance)
                {
                    lengthEven = 2 * distance;
                    indexEven = i;
                }
            }
        }

        if (lengthOdd > lengthEven)
            return s.Substring(indexOdd - lengthOdd / 2, lengthOdd);
        return s.Substring(indexEven - lengthEven / 2 + 1, lengthEven);
    }
}


