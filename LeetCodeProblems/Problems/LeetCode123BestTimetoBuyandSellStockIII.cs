namespace LeetCodeProblems.Problems;

public class LeetCode123BestTimetoBuyandSellStockIII: BaseProblemClass
{
    public int MaxProfit(int[] prices)
    {
        int length = prices.Length;
        int[] maxFromLeft = new int[length];
        int[] maxFromRight = new int[length];
        int maxProfit = 0;
        int minBuyPrice = prices[0];
        int profit = 0;
        for (int i = 1; i < length; i++)
        {
            profit = prices[i] - minBuyPrice;
            if (profit > maxProfit)
                maxProfit = profit;
            maxFromLeft[i] = maxProfit;
            if (prices[i] < minBuyPrice)
                minBuyPrice = prices[i];
        }

        minBuyPrice = prices[^1];
        maxProfit = 0;
        profit = 0;
        int totalProfit = 0;
        int twoTradeProfit = 0;
        for (int i = length - 2; i >= 0; i--)
        {
            profit =minBuyPrice- prices[i];
            if(profit>maxProfit)
                maxProfit = profit;
            maxFromRight[i] = maxProfit;
            if(prices[i] > minBuyPrice)
                minBuyPrice = prices[i];
            twoTradeProfit = maxFromLeft[i] + maxFromRight[i];
            if(twoTradeProfit > totalProfit)
                totalProfit = twoTradeProfit;
        }

        return totalProfit;
    }

    public override void Run()
    {
        int[] prices = [3, 3, 5, 0, 0, 3, 1, 4];
        Console.WriteLine(MaxProfit(prices));
    }
}