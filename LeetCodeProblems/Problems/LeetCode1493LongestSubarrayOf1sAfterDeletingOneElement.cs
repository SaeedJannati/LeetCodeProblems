namespace LeetCodeProblems.Problems;

public class LeetCode1493LongestSubarrayOf1sAfterDeletingOneElement
{
    public int LongestSubarray(int[] nums)
    {
        if (nums == null || nums.Length == 0)
            return 0;
        if (nums.Length == 1)
            return 0;
        int length = nums.Length;
        int zeroNum = 0;
        int firstPointer = 0;
        int secondPointer = 0;
        if (nums[0] == 0)
            zeroNum++;
        int output = 0;
        while (secondPointer < length - 1)
        {
            secondPointer++;
            if (nums[secondPointer] == 0)
                zeroNum++;
            while (zeroNum > 1 && secondPointer < length - 1)
            {
                firstPointer++;
                secondPointer++;
                if (nums[firstPointer - 1] == 0)
                    zeroNum--;
                if (nums[secondPointer] == 0)
                    zeroNum++;
            }

            if (zeroNum <= 1)
                output = Math.Max(output, secondPointer - firstPointer);
        }

        if (output == length)
            output--;
        return output;
    }
}