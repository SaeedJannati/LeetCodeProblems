namespace LeetCodeProblems.Problems;

public class LeetCode152MaximumProductSubarray: BaseProblemClass
{
    public int MaxProduct(int[] nums)
    {
        int length=nums.Length;
        if(length==1)
            return nums[0];
        int[,] dp = new int[length,2];
        dp[0,0]=nums[0];
        if(nums[0]<0)
            dp[0,1]=nums[0];
        
        int max = dp[0,0];
        for (int i = 1; i < length; i++)
        {
            dp[i,0]=Math.Max(dp[i-1,0]*nums[i],Math.Max(dp[i-1,1]*nums[i],nums[i]));
        if(dp[i,0]>max)
            max = dp[i,0];
        dp[i,1]=Math.Min(dp[i-1,0]*nums[i],Math.Min(dp[i-1,1]*nums[i],nums[i]));
        if (dp[i, 1] > 0)
            dp[i, 1] = 0;
        }

        return max;
    }

    public override void Run()
    {
        int[] nums = [-2, 3, -4];
        Console.WriteLine(MaxProduct(nums));
    }
}