namespace LeetCodeProblems.Problems;

public class LeetCode163SumClosest
{
    public int ThreeSumClosest(int[] nums, int target)
    {
        int length = nums.Length;
        if (length == 3)
            return nums.Sum();
        Array.Sort(nums);
        int firstPointer = 0;
        int secondPointer = 0;
        int closest = 0;
        int lowestDelta = int.MaxValue;
        int delta = int.MaxValue;
        int sum = 0;
        int sum1 = 0;
        int delta1 = Int32.MaxValue;
        int sum2 = 0;
        int delta2 = Int32.MaxValue;
        for (int i = 0; i < length-2; i++)
        {
            firstPointer = i + 1;
            secondPointer = length - 1;
            while (firstPointer < secondPointer)
            {
                sum = nums[i] + nums[firstPointer] + nums[secondPointer];
                delta = Math.Abs(sum - target);
                if (delta == 0)
                    return target;
                if (delta < lowestDelta)
                {
                    lowestDelta = delta;
                    closest = sum;
                }

                sum1 = nums[i] + nums[firstPointer + 1] + nums[secondPointer];
                delta1 = Math.Abs(sum1 - target);
                sum2 = nums[i] + nums[firstPointer] + nums[secondPointer - 1];
                delta2 = Math.Abs(sum2 - target);
                if (delta1 < delta2)
                    firstPointer++;
                else
                    secondPointer--;
            }
        }
        return closest;
    }
}