namespace LeetCodeProblems.Problems;

public class LeetCode918MaximumSumCircularSubarray : BaseProblemClass
{
    public int MaxSubarraySumCircular(int[] nums)
    {
        var length = nums.Length;
        int minUptoLast = nums[0];
        int maxUptoLast = nums[0];
        int minSum = minUptoLast;
        int maxSum = maxUptoLast;
        int sum = nums[0];
        for (int i = 1; i < length; i++)
        {
            minUptoLast=Math.Min(nums[i]+minUptoLast,nums[i] );
            maxUptoLast = Math.Max(nums[i]+maxUptoLast,nums[i] );
            sum += nums[i];
            if(minUptoLast<minSum)
                minSum = minUptoLast;
            if(maxUptoLast > maxSum)
                maxSum = maxUptoLast;
        }
        sum-=minSum;
        if (sum == 0)
            return maxSum;
        return Math.Max(maxSum,sum);
    }

    public override void Run()
    {
        int[] input = [-2];
        Console.WriteLine(MaxSubarraySumCircular(input));
    }
}