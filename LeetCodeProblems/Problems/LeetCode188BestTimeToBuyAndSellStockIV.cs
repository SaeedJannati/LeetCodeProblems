namespace LeetCodeProblems.Problems;

public class LeetCode188BestTimeToBuyAndSellStockIV
{
    public int MaxProfit(int k, int[] prices)
    {
        var length = prices.Length;
        var dp = new int[length, k + 1, 2];
        //0-> no-state 1->bought
        for (int i = 1; i < length; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                for (int l = 0; l < 2; l++)
                {
                    if (l == 0)
                    {
                        dp[i, j, l] = Math.Max(dp[i - 1, j, 0], dp[i - 1, j, 1]);
                        continue;
                    }
                }
            }
        }

        return 0;
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