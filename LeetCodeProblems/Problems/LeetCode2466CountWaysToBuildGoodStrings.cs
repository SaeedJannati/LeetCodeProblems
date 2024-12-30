namespace LeetCodeProblems.Problems;

public class LeetCode2466CountWaysToBuildGoodStrings : BaseProblemClass
{
    public int CountGoodStrings(int low, int high, int zero, int one)
    {
        if (zero > high && one > high)
            return 0;
        int moduloNum = 1_000_000_000 + 7;
        int[] dp = new int[high + 1];
        dp[0] = 1;
        for (int i = 0; i <= high; i++)
        {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % moduloNum;
            if (i >= one)
            {
                dp[i] = (dp[i] + dp[i - one]) % moduloNum;
            }
        }
        int result = 0;
        for (int i = low; i <= high; i++)
        {
            result = (result + dp[i]) % moduloNum;
        }
        return result;
    }

    public override void Run()
    {
        int low = 1;
        int high = 100000;
        int zero = 1;
        int one = 1;
        Console.WriteLine(CountGoodStrings(low, high, zero, one));
    }
}