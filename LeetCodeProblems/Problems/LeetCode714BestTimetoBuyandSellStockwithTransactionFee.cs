namespace LeetCodeProblems.Problems;

public class LeetCode714BestTimetoBuyandSellStockwithTransactionFee : BaseProblemClass
{
   

    public int MaxProfit(int[] prices, int fee)
    {
        var length = prices.Length;
        int[,] dp = new int[length, 2];
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i, j] = -1;
            }
        }
        return MaxProfitRecursive(length-1 , 1, prices, fee,dp);
    }

    int MaxProfitRecursive(int day, int canBuy, int[] prices, int fee, int[,] dp)
    {
        if (dp[day, canBuy] != -1)
            return dp[day, canBuy];
        if (day == 0)
        {
           if(canBuy==0)
               return -prices[0];
           return 0;
        }

        if (canBuy == 1)
        {
            dp[day, canBuy]= Math.Max(MaxProfitRecursive(day - 1, 1, prices, fee, dp),
                MaxProfitRecursive(day - 1, 0, prices, fee, dp) + prices[day] - fee);
            return dp[day, canBuy];
        }

        dp[day, canBuy]= Math.Max(MaxProfitRecursive(day - 1, 0, prices, fee, dp),
            MaxProfitRecursive(day - 1, 1, prices, fee, dp) - prices[day]);
        return dp[day, canBuy];
    }
    public override void Run()
    {
        int[] prices = [1,3,7,5,10,3];
        int fee = 3;
        Console.WriteLine("Max Profit: {0}", MaxProfit(prices, fee));
    }
}