namespace LeetCodeProblems.Problems;

public class LeetCode1800MaximumAscendingSubarraySum
{
    public int MaxAscendingSum(int[] nums)
    {
        int maxSum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            if (nums[i] > nums[i - 1])
                sum+=nums[i];
            else
                sum = nums[i];
            if(sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
}