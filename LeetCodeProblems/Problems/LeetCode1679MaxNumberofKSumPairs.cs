namespace LeetCodeProblems.Problems;

public class LeetCode1679MaxNumberofKSumPairs
{
    public int MaxOperations(int[] nums, int k)
    {
        if (nums.Length <= 1)
            return 0;
        Array.Sort(nums);
        if (k <= nums[0])
            return 0;
        int length = nums.Length;
        int begin = 0;
        int end = length - 1;
        int mid = 0;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            if (nums[mid] < k)
            {
                if (mid == length - 1)
                    break;
                if (nums[mid + 1] >= k)
                    break;
                begin = mid + 1;
            }
            else
            {
                if (nums[mid - 1] < k)
                {
                    mid--;
                    break;
                }

                end = mid - 1;
            }
        }

        int firstPointer = 0;
        int secondPointer = mid;
        int output = 0;
        int sum = 0;
        while (firstPointer < secondPointer)
        {
            sum = nums[firstPointer] + nums[secondPointer];
            if (sum == k)
            {
                output++;
                firstPointer++;
                secondPointer--;
                continue;
            }

            if (sum > k)
            {
                secondPointer--;
                continue;
            }

            firstPointer++;
        }

        return output;
    }
}