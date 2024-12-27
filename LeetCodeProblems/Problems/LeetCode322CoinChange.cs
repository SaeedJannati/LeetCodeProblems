namespace LeetCodeProblems.Problems;

public class LeetCode322CoinChange : BaseProblemClass
{
    public override void Run()
    {
        int[] coins = [2];
        int amount = 3;
        int outPut = CoinChange(coins, amount);
        Console.WriteLine(outPut);
    }

    public int CoinChange(int[] coins, int amount)
    {
        if (coins == null)
            return -1;
        if (coins.Length == 0)
            return -1;
        if (amount == 0)
            return 0;
        List<int> orderedCoins = [..coins];
        for (int i = orderedCoins.Count - 1; i >= 0; i--)
        {
            if (orderedCoins[i] > amount)
                orderedCoins.RemoveAt(i);
        }

        if (orderedCoins.Count == 0)
            return -1;
        Dictionary<int, int> minCoinPerValue = [];
        minCoinPerValue[0] = 0;
        var dp = Enumerable.Range(0, orderedCoins.Count)
            .Select(_ => Enumerable.Repeat(0, amount+1).ToList())
            .ToList();
        int delta = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0, e = orderedCoins.Count; j < e; j++)
            {
                delta = i - orderedCoins[j];
                if (delta < 0)
                    continue;
                if(!minCoinPerValue.ContainsKey(delta))
                    continue;
                dp[j][i] = 1 + minCoinPerValue[delta];
                if (!minCoinPerValue.ContainsKey(i))
                {
                    minCoinPerValue[i] = dp[j][i];
                    continue;
                }

                if (dp[j][i] < minCoinPerValue[i])
                    minCoinPerValue[i] = dp[j][i];
            }
        }

        var outPut = -1;
        if(minCoinPerValue.ContainsKey(amount))
            outPut = minCoinPerValue[amount];
        return outPut;
    }
}