namespace LeetCodeProblems.Problems;

public class LeetCode300LongestIncreasingSubsequence: BaseProblemClass
{
    public int LengthOfLIS(int[] nums)
    {
        if (nums.Length == 0)
            return 0;
        if (nums.Length == 1)
            return 1;
        int maxLength = 1;
        int current = 0;
        List<int> dp=Enumerable.Repeat(1, nums.Length).ToList();
        for (int i = 1; i < nums.Length; i++)
        {
            current = 1;
            for (int j = 0; j < i; j++)
            {
                if(nums[i] <= nums[j])
                    continue;
                if(dp[j]+1>current)
                    current=dp[j]+1;
            }
            dp[i] = current;
            if(current>maxLength)
                maxLength = current;
        }
        return maxLength;
    }

    public override void Run()
    {
        int[] input = [0, 1, 0, 3, 2, 3];
        Console.WriteLine(LengthOfLIS(input));
    }
}