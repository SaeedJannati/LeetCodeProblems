namespace LeetCodeProblems.Problems;

public class LeetCode213HouseRobberII
{
    #region O(1) memory

    public int Rob(int[] nums)
    {
        int length = nums.Length;
        if (length == 0)
            return 0;
        if (length == 1)
            return nums[0];
        int[] dp = new int[2];
        dp[0] = nums[0];
        dp[1] = nums[0];
        for (int i = 2; i < length - 1; i++)
        {
            dp[0] = Math.Max(dp[1], dp[0] + nums[i]);
            (dp[0], dp[1]) = (dp[1], dp[0]);
        }
    
        int max = dp[^1];
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < length; i++)
        {
            dp[0] = Math.Max(dp[1], dp[0] + nums[i]);
            (dp[0], dp[1]) = (dp[1], dp[0]);
        }
    
        return Math.Max(max, dp[^1]);
    }

    #endregion
    #region O(n) memory

    // public int Rob(int[] nums)
    // {
    //     int length = nums.Length;
    //     if (length == 0)
    //         return 0;
    //     if (length == 1)
    //         return nums[0];
    //     int[] dp = new int[length];
    //     dp[0] = nums[0];
    //     dp[1] = nums[0];
    //     for (int i = 2; i < length - 1; i++)
    //     {
    //         dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i]);
    //     }
    //
    //     int max = dp[^2];
    //     dp[0] = 0;
    //     dp[1] = nums[1];
    //     for (int i = 2; i < length; i++)
    //     {
    //         dp[i] = Math.Max(dp[i - 1], dp[i - 2] + nums[i]);
    //     }
    //
    //     return Math.Max(max, dp[^1]);
    // }

    #endregion
}


