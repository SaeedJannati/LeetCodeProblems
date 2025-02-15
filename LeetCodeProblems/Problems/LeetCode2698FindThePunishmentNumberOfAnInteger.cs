namespace LeetCodeProblems.Problems;

public class LeetCode2698FindThePunishmentNumberOfAnInteger : BaseProblemClass
{
    public int PunishmentNumber(int n)
    {
        int sum = 1;
        int square = 0;
        int[] digits = Enumerable.Repeat(0, 7).ToArray();
        for (int i = 9; i <= n; i++)
        {
            square = i * i;
            if (!ShouldBeIncluded(square, i, digits))
                continue;
            sum += square;
        }

        return sum;
    }

    bool ShouldBeIncluded(int square, int num, int[] digits)
    {
        int length = 0;
        while (square > 0)
        {
            digits[length] = (square % 10);
            square /= 10;
            length++;
        }

        return GetNumber(digits, length - 1, 0, num);
    }

    bool GetNumber(int[] digits, int index, int sum, int num)
    {
        if (index < 0)
            return sum == num;
        int newSum = 0;
        int powerOfTen = 1;
        for (int i = index; i >= 0; i--)
        {
            powerOfTen = 1;
            newSum = 0;
            for (int j = i; j <= index; j++)
            {
                newSum += digits[j] * powerOfTen;
                powerOfTen *= 10;
            }

            if (GetNumber(digits, i - 1, newSum + sum, num))
                return true;
        }

        return false;
    }

    public override void Run()
    {
        int n =
            1000;
        // 10; 
        // 37;
        Console.WriteLine(PunishmentNumber(n));
    }


    #region Easier to understand
        // public int PunishmentNumber(int n)
        // {
        //     int sum = 1;
        //     int square = 0;
        //     for (int i = 9; i <= n; i++)
        //     {
        //         square = i*i;
        //         if(!ShouldBeIncluded(square,i))
        //             continue;
        //         sum += square;
        //     }
        //     return sum;
        // }
        //
        // bool ShouldBeIncluded(int square, int num)
        // {
        //     List<int> digits = new List<int>();
        //     while (square>0)
        //     {
        //         digits.Add(square % 10);
        //         square /= 10;
        //     }
        //     digits.Reverse();
        //     return GetNumber(digits, digits.Count,0,0,num);
        // }
        //
        // bool GetNumber(List<int> digits, int length, int index, int sum, int num)
        // {
        //     if (index == length)
        //         return sum == num;
        //     int newSum = 0;
        //     int powerOfTen = 1;
        //     for (int i = index ; i < length; i++)
        //     {
        //         powerOfTen = 1;
        //         newSum = 0;
        //         for (int j = i; j >= index; j--)
        //         {
        //             newSum += digits[j] * powerOfTen;
        //             powerOfTen *= 10;
        //         }
        //
        //         if (GetNumber(digits, length, i+1 , newSum+sum, num))
        //             return true;
        //     }
        //
        //     return false;
        // }
    #endregion
}