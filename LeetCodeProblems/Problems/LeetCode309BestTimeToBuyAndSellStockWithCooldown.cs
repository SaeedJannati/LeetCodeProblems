namespace LeetCodeProblems.Problems;

public class LeetCode309BestTimeToBuyAndSellStockWithCooldown : BaseProblemClass
{
    #region memoisation array

    private int[][] memoisation;

    int FindMaxProfit(int[] prices, int day, int isCooldown, int hasStock)
    {
        var secondIndex = (byte)(isCooldown << 1 | hasStock);
        if (memoisation[day][secondIndex] != -5000)
            return memoisation[day][secondIndex];
        memoisation[day][secondIndex] = isCooldown switch
        {
            1 when hasStock == 0 => FindMaxProfit(prices, day - 1, 0, 1) + prices[day - 1],
            0 when hasStock == 0 => int.Max(FindMaxProfit(prices, day - 1, 0, 0), FindMaxProfit(prices, day - 1, 1, 0)),
            0 when hasStock == 1 => int.Max(FindMaxProfit(prices, day - 1, 0, 0) - prices[day - 1],
                FindMaxProfit(prices, day - 1, 0, 1)),
            _ => memoisation[day][secondIndex]
        };

        return memoisation[day][secondIndex];
    }

    public int MaxProfit(int[] prices)
    {
        int length = prices.Length;
        memoisation = Enumerable.Range(0, length).Select(_ => Enumerable.Repeat(-5000, 4).ToArray()).ToArray();
        memoisation[0][0] = 0;
        memoisation[0][1] = -prices[0];
        memoisation[0][2] = -4000;
        memoisation[0][3] = -4000;
        if (length > 1)
        {
            memoisation[1][2] = -4000;
            memoisation[1][3] = -4000;
        }
        int maxProfit =
            FindMaxProfit(prices, length - 1, 1, 0);
        maxProfit = int.Max(maxProfit, FindMaxProfit(prices, length - 1, 0, 1) + prices[length - 1]);
        maxProfit = int.Max(maxProfit, FindMaxProfit(prices, length - 1, 0, 0));
        return maxProfit > 0 ? maxProfit : 0;
    }

    #endregion

    #region memoisation dictionary

    // private Dictionary<(int day, bool isCooldown, bool hasStock), int> memoisation = [];
    //
    // int FindMaxProfit(int[] prices, int day, bool isCooldown, bool hasStock)
    // {
    //     if (day == 0)
    //     {
    //         if (isCooldown)
    //             return -5000;
    //         if (hasStock)
    //             return -prices[0];
    //         return 0;
    //     }
    //
    //     if (day == 1)
    //     {
    //         if (isCooldown)
    //             return -5000;
    //     }
    //
    //     if (memoisation.TryGetValue((day, isCooldown, hasStock), out var maxProfit))
    //         return maxProfit;
    //     if (isCooldown && !hasStock)
    //     {
    //         memoisation[(day, isCooldown, hasStock)]=FindMaxProfit(prices, day - 1, false, true)+prices[day-1];
    //     }
    //
    //     if (!isCooldown && !hasStock)
    //     {
    //         memoisation[(day, isCooldown, hasStock)]= int.Max(FindMaxProfit(prices, day - 1, false, false),
    //             FindMaxProfit(prices, day - 1, true, false));
    //     }
    //
    //     if (!isCooldown && hasStock)
    //     {
    //         memoisation[(day, isCooldown, hasStock)]  = int.Max(FindMaxProfit(prices, day - 1, false, false)-prices[day-1],
    //             FindMaxProfit(prices, day - 1, false, true));
    //     }
    //
    //     return memoisation[(day, isCooldown, hasStock)];
    // }
    //
    // public int MaxProfit(int[] prices)
    // {
    //     int length = prices.Length;
    //
    //     int maxProfit =
    //         FindMaxProfit(prices, length - 1, true, false);
    //     maxProfit = int.Max(maxProfit, FindMaxProfit(prices, length - 1, false, true)+prices[length-1]);
    //     maxProfit=int.Max(maxProfit,FindMaxProfit(prices, length - 1, false, false));
    //     return maxProfit > 0 ? maxProfit : 0;
    // }

    #endregion


    public override void Run()
    {
        int[] prices =
            [1, 7, 2, 4];
        // [1, 2, 4];
        // [1,2,3,0,2]; 
        // [1];
        // [2, 1]; 
        // [1,2];
        Console.WriteLine(MaxProfit(prices));
    }
}