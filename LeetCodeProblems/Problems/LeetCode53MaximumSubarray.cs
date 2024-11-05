namespace LeetCodeProblems.Problems;

public class LeetCode53MaximumSubarray
{
    public int MaxSubArray(int[] nums)
    {
        if (nums.Length == 0)
            return 0;
        if(nums.Length == 1)
            return nums[0];
        int max = nums[0];
        for (int i = 1, e = nums.Length; i < e; i++)
        {
            nums[i] = Math.Max(nums[i], nums[i - 1]+nums[i]);
            if(nums[i]>max)
                max = nums[i];
        }
        return max;
    }
}