namespace LeetCodeProblems.Problems;

public class LeetCode209MinimumSizeSubarraySum
{
    public int MinSubArrayLen(int target, int[] nums)
    {
        int firstPointer = 0;
        int currentSum = 0;
        int length = 0;
        int minLength = nums.Length;
        for (int i = 0, e = nums.Length; i < e; i++)
        {
                currentSum+=nums[i];
            if(currentSum<target)
                continue;
            for (int j = firstPointer; j < i; j++)
            {
                if(currentSum-nums[j]<target)
                    break;
                currentSum-=nums[j];
                firstPointer++;
            }
            length=i-firstPointer;
            if(length<minLength)
                minLength = length;
        }

        if (currentSum < target)
            return 0;
        return minLength+1;
    }
}