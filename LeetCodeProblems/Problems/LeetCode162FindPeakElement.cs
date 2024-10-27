namespace LeetCodeProblems.Problems;

public class LeetCode162FindPeakElement : BaseProblemClass
{
    public int FindPeakElement(int[] nums)
    {
        if (nums == null || nums.Length == 0)
            return 0;
        int length = nums.Length - 1;
        if (length == 0)
            return 0;
        int begin = 0;
        int end = length;
        int mid = 0;
        int newMid = 0;
        while (true)
        {
            mid = (begin + end) / 2;
            if (CheckIfPeak(nums, mid, length))
                return mid;
            if (mid > 0 && nums[mid] <= nums[mid - 1])
                end = mid;
            else
                begin = mid;
            newMid = (begin + end) / 2;
            if (newMid == mid)
            {
                if (CheckIfPeak(nums, mid, length))
                    return mid;
                if (newMid == 0)
                    if (CheckIfPeak(nums, 0, length))
                        return 0;
                if (newMid == length)
                    if (CheckIfPeak(nums, length, length))
                        return length;
                if (nums[mid + 1] > nums[mid])
                    return mid + 1;
                return mid - 1;
            }
        }
    }

    private bool CheckIfPeak(int[] nums, int mid, int length)
    {
        if (mid == 0)
        {
            if (nums[0] > nums[1])
                return true;
            return false;
        }

        if (mid == length)
        {
            if (nums[length] > nums[length - 1])
                return true;
            return false;
        }

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return true;
        return false;
    }

    public override void Run()
    {
        int[] nums = [1, 2];
        Console.WriteLine(FindPeakElement(nums));
    }
}