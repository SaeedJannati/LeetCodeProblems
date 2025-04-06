namespace LeetCodeProblems.Problems;

public class LeetCode368LargestDivisibleSubset : BaseProblemClass
{
    public IList<int> LargestDivisibleSubset(int[] nums)
    {
        if (nums.Length == 1)
            return nums.ToList();
        Array.Sort(nums);
        Dictionary<int, List<int>> dp = [];
        foreach (var num in nums)
        {
            dp[num] = [num];
        }
        int maxLength = 0;
        int maxIndex = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[nums[i]].Count < dp[nums[j]].Count+1)
                    {
                        dp[nums[i]] = [..dp[nums[j]], nums[i]];
                    }
                }
                if (dp[nums[i]].Count > maxLength)
                {
                    maxLength = dp[nums[i]].Count;
                    maxIndex = nums[i];
                }
            }
        }
        return dp[maxIndex];
    }

    public override void Run()
    {
        int[] nums = [1, 2, 3, 4, 6, 24];
        var result = LargestDivisibleSubset(nums);
        Console.WriteLine(string.Join(", ", result));
    }
}