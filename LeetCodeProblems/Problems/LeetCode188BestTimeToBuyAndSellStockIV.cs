namespace LeetCodeProblems.Problems;

public class LeetCode188BestTimeToBuyAndSellStockIV: BaseProblemClass
{
    public int MaxProfit(int k, int[] prices)
    {
        var length = prices.Length;
        var dp =Enumerable.Range(0, length+1)
            .SelectMany(i => Enumerable.Range(0, k+1)
                .SelectMany(j => Enumerable.Range(0, 2)
                    .Select(k => new { i, j, k })))
            .Aggregate(new int[length+1, k+1, 2], (arr, idx) =>
            {
                arr[idx.i, idx.j, idx.k] = -1;
                return arr;
            });
        return MaxProfitRecursive(0,0,prices,1,dp,k,length);
    }

    private int MaxProfitRecursive(int transactionNumber,int day, int[] prices, int canBuy, int[,,] dp,int k,int length)
    {
        if (transactionNumber > k-1 || day > length-1)
            return 0;
        if(dp[day, transactionNumber, canBuy]!=-1)
            return dp[day, transactionNumber, canBuy];
        if (canBuy == 1)
        {
            dp[day,transactionNumber,canBuy]= Math.Max(
                -prices[day]+MaxProfitRecursive(transactionNumber,day+1,prices,0,dp,k,length),
                MaxProfitRecursive(transactionNumber,day+1,prices,1,dp,k,length)
                );
        }
        else
        {
            dp[day,transactionNumber,canBuy]= Math.Max(
                prices[day] + MaxProfitRecursive(transactionNumber + 1, day + 1, prices, 1, dp, k, length),
                MaxProfitRecursive(transactionNumber, day + 1, prices, 0, dp, k, length)
            );
        }

        return dp[day, transactionNumber, canBuy];
    }

    public override void Run()
    {
        int[] prices = [3,2,6,5,0,3];
        int k = 2;
        Console.WriteLine(MaxProfit(k, prices));
    }
}

public class Solution
{
    public int RecursionWithMemoization(int[] p, int ind, bool canBuy, int k, int[][][] dp)
    {
        if (ind >= p.Length || k <= 0)
            return 0;

        if (dp[ind][canBuy ? 1 : 0][k] != -1)
            return dp[ind][canBuy ? 1 : 0][k];

        int maxProfit;
        if (canBuy)
        {
            maxProfit = Math.Max(-p[ind] + RecursionWithMemoization(p, ind + 1, false, k, dp),
                RecursionWithMemoization(p, ind + 1, true, k, dp));
        }
        else
        {
            maxProfit = Math.Max(p[ind] + RecursionWithMemoization(p, ind + 1, false, k - 1, dp),
                RecursionWithMemoization(p, ind + 1, true, k, dp));
        }

        dp[ind][canBuy ? 1 : 0][k] = maxProfit;
        return maxProfit;
    }

    public int MaxProfit(int[] prices)
    {
        int k = 2; // change the value of k as per the question
        int[][][] dp = new int[prices.Length + 1][][];
        for (int i = 0; i <= prices.Length; i++)
        {
            dp[i] = new int[3][];
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = new int[k + 1];
                for (int l = 0; l <= k; l++)
                {
                    dp[i][j][l] = -1;
                }
            }
        }

        return RecursionWithMemoization(prices, 0, true, k, dp);
    }
}