namespace LeetCodeProblems.Problems;

public class LeetCode35SearchInsertPosition : BaseProblemClass
{
    public int SearchInsert(int[] nums, int target)
    {
        if (nums.Length == 0)
            return 0;
        if (nums.Length == 1)
            return target > nums[0] ? 1 : 0;
        int length = nums.Length;
        int begin = 0;
        int end = length - 1;
        int mid = 0;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }

        if (mid == 0)
            return target < nums[0] ? 0 : 1;
        if (mid == nums.Length - 1)
            return target < nums[^1] ? nums.Length - 1 : nums.Length;
        if (target > nums[mid])
            return mid + 1;
        return mid;
    }

    public override void Run()
    {
        int[] nums = [3,5,7,9,10];
        int target = 8;
        Console.WriteLine(SearchInsert(nums, target));
    }
}