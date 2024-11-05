using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode122BestTimeToBuyAndSellStockII: BaseProblemClass
{
    public int MaxProfit(int[] prices)
    {
        if (prices.Length == 0)
            return 0;
        if (prices.Length == 1)
            return 0;
        int profit = 0;
        for (int i = 0; i < prices.Length-1; i++)
        {
            if(prices[i+1]>prices[i])
                profit+=prices[i+1]-prices[i];
        }

        return profit;
    }

    public override void Run()
    {
        int[] input = [7,1,5,3,6,4];
        var maxProfit=MaxProfit(input);
        Console.WriteLine(maxProfit);
    }
}