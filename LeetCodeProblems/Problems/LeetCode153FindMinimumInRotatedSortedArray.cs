namespace LeetCodeProblems.Problems;

public class LeetCode153FindMinimumInRotatedSortedArray: BaseProblemClass
{
    public int FindMin(int[] nums)
    {
        if (nums.Length == 0)
            return 0;
        if (nums.Length == 1)
            return nums[0];
        int rotationPoint=FindRotationPoint(nums);
        return nums[rotationPoint];
    }

    private int FindRotationPoint(int[] nums)
    {
        if (nums[0] < nums[^1])
            return 0;
        int begin = 0;
        int length = nums.Length - 1;
        int end = length;
        int mid = 0;
        int newMid = 0;
        int previous = 0;
        int next = 0;
        while (true)
        {
            mid = (begin + end) / 2;
            previous = mid == 0 ? length : mid - 1;
            next = mid == length ? 0 : mid + 1;
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
                int newNext = mid + 1 == length ? 0 : mid + 2;
                if (nums[next] < nums[mid] && nums[next] <nums[newNext])
                    return next;
                return previous;
            }
        }
    }

    public override void Run()
    {
       
    }
}