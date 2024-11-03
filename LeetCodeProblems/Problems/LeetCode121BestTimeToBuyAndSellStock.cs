namespace LeetCodeProblems.Problems;

public class LeetCode121BestTimeToBuyAndSellStock : BaseProblemClass
{
    public int MaxProfit(int[] prices)
    {
        int bestBuyPrice = prices[0];
        int mostProfit = 0;
        int profit = 0;
        for (int i = 1,e=prices.Length; i < e; i++)
        {
            profit= prices[i]-bestBuyPrice;
            if(profit > mostProfit)
                mostProfit=profit;
            if(prices[i]<bestBuyPrice)
                bestBuyPrice = prices[i];
        }
        return mostProfit;
    }

    // nlogN
    // public int MaxProfit(int[] prices)
    // {
    //     var results = new SortedList<int, int>(prices.Length);
    //     Dictionary<int, int> frequencies = new Dictionary<int, int>(prices.Length);
    //     foreach (var price in prices)
    //     {
    //         
    //         if (frequencies.ContainsKey(price))
    //             frequencies[price]++;
    //         else
    //         {
    //             frequencies[price] = 1;
    //             results.Add(-price, price);
    //         }
    //
    //         
    //     }
    //
    //     int delta = 0;
    //     int maxSoFar = 0;
    //     for (int i = 0, e = prices.Length - 1; i < e; i++)
    //     {
    //         frequencies[prices[i]]--;
    //         if (frequencies[prices[i]] == 0)
    //             results.Remove(-prices[i]);
    //         delta = results.First().Value - prices[i];
    //         if (delta > maxSoFar)
    //             maxSoFar = delta;
    //     }
    //
    //     return maxSoFar;
    // }

    public override void Run()
    {
        int[] prices = [3,3];
        Console.WriteLine(MaxProfit(prices));
    }
}