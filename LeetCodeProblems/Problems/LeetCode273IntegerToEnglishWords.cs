using System.Text;

namespace LeetCodeProblems.Problems;

public class LeetCode273IntegerToEnglishWords : BaseProblemClass
{
    private Dictionary<int, string> dict = new Dictionary<int, string>()
    {
        {0,""},
        { 1, "One " },
        { 2, "Two " },
        { 3, "Three " },
        { 4, "Four " },
        { 5, "Five " },
        { 6, "Six " },
        { 7, "Seven " },
        { 8, "Eight " },
        { 9, "Nine " },
        { 10, "Ten " },
        { 11, "Eleven " },
        { 12, "Twelve " },
        { 13, "Thirteen " },
        { 14, "Fourteen " },
        { 15, "Fifteen " },
        { 16, "Sixteen " },
        { 17, "Seventeen " },
        { 18, "Eighteen " },
        { 19, "Nineteen " },
        { 20, "Twenty " },
        { 30, "Thirty " },
        { 40, "Forty " },
        { 50, "Fifty " },
        { 60, "Sixty " },
        { 70, "Seventy " },
        { 80, "Eighty " },
        { 90, "Ninety " },
        { 100, "Hundred " },
        { 1_000, "Thousand " },
        { 1_000_000, "Million " },
        { 1_000_000_000, "Billion " }
    };

    string GetPartString(List<int> num, int powerOfThousand)
    {
        if (num[0] == 0 && num[1] == 0 && num[2] == 0)
            return "";
        var powerOfThousandStr = "";
        if (powerOfThousand > 0)
        {
            powerOfThousandStr = dict[(int)Math.Pow(1000, powerOfThousand)];
        }

        StringBuilder builder = new StringBuilder();
        if (num[2] > 0)
        {
            builder.Append(dict[num[2]]);
            builder.Append(dict[100]);
        }

        if (num[1] <= 1)
        {
            builder.Append(dict[num[1] * 10 + num[0]]);
            builder.Append(powerOfThousandStr);
            return builder.ToString();
        }

        builder.Append(dict[num[1] * 10]);
        builder.Append(dict[num[0]]);
        builder.Append(powerOfThousandStr);
        return builder.ToString();
    }

    public string NumberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        int powerOfThousand = 0;
        List<int> nums = [];
        List<string> parts = [];
        while (num > 0)
        {
            nums = [0,0,0];
            for (int i = 0; i < 3; i++)
            {
                nums[i]=num % 10;
                num /= 10;
            }
            parts.Add(GetPartString(nums, powerOfThousand));
            powerOfThousand ++;
        }

        parts.Reverse();
        var result = string.Join("", parts);
        result = result.Remove(result.Length - 1, 1);
        return result;
    }

    public override void Run()
    {
        int num = 100123;
        Console.WriteLine(NumberToWords(num));
    }
}