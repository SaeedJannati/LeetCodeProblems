namespace LeetCodeProblems.Problems;

public class LeetCode33SearchInRotatedSortedArray : BaseProblemClass
{
    public int Search(int[] nums, int target)
    {
        var rotateIndex = FindRotationIndex(nums);
        if (target < nums[rotateIndex])
            return -1;
        int maxIndex = rotateIndex == 0 ? nums.Length - 1 : rotateIndex - 1;
        if (target > nums[maxIndex])
            return -1;
        if (rotateIndex == 0)
            return TryFindTarget(nums, 0, nums.Length - 1, target);
        if (target <= nums[^1])
            return TryFindTarget(nums, rotateIndex, nums.Length - 1, target);
        return TryFindTarget(nums, 0, rotateIndex-1, target);
    }

    int TryFindTarget(int[] nums, int initIndex, int endIndex, int target)
    {
        int begin = initIndex;
        int end = endIndex;
        int mid;
        int newMid;
        while (true)
        {
            mid = (begin + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (target < nums[mid])
                end = mid;
            else
                begin = mid;
            newMid=(begin + end) / 2;
            if (newMid == mid)
            {
                int previous = mid == 0 ? 0 : mid - 1;
                int next = mid == end ? end : mid + 1;
                if (target == nums[next])
                    return next;
                if (target == previous)
                    return previous;
                return -1;
            }
        }
    }

    int FindRotationIndex(int[] nums)
    {
        int length = nums.Length - 1;
        if (length <= 0)
            return 0;
        if (nums[0] < nums[^1])
            return 0;
        int begin = 0;
        int end = length;
        int mid = 0;
        int newMid = 0;
        int previous = 0;
        int next = 0;
        while (true)
        {
            mid = (begin + end) / 2;
            next = mid < length  ? mid + 1 : 0;
            previous = mid > 0 ? mid - 1 : length;
            if (nums[mid] < nums[previous] && nums[mid] < nums[next])
                return mid;
            if (nums[mid] > nums[end])
            {
                begin = mid;
            }
            else
            {
                end = mid;
            }

            newMid = (begin + end) / 2;
            if (newMid == mid)
            {
                mid = previous;
                next = mid < length ? mid + 1 : 0;
                previous = mid > 0 ? mid - 1 : length;
                if (nums[mid] < nums[previous] && nums[mid] < nums[next])
                    return mid;
                next = newMid < length ? newMid + 1 : 0;
                return next;
            }
        }
    }

    public override void Run()
    {
        int[] input = [3,5,1];
        int target = 1;
        Console.WriteLine(Search(input, target));
    }
}