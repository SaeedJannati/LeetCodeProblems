using LeetCodeProblems.Models;

namespace LeetCodeProblems.Problems;

public class LeetCode334IncreasingTripletSubsequence
{
    public bool IncreasingTriplet(int[] nums)
    {
        int length = nums.Length;
        if (length < 3)
            return false;
        int[] leftMin = new int[length];
        int[] rightMax = new int[length];
        int minLeft = int.MaxValue;
        int maxRight = int.MinValue;
        for (int i = 0; i < length; i++)
        {
            if (nums[i] < minLeft)
                minLeft = nums[i];
            leftMin[i] = minLeft;
        }

        for (int i = length - 1; i >= 0; i--)
        {
            if (nums[i] > maxRight)
                maxRight = nums[i];
            rightMax[i] = maxRight;
        }

        for (int i = 1; i < length - 1; i++)
        {
            if (nums[i] <= leftMin[i] )
                continue;
            if(nums[i] >= rightMax[i])
                continue;
            return true;

        }

        return false;
    }
}