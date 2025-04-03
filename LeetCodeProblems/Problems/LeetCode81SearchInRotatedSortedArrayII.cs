namespace LeetCodeProblems.Problems;

public class LeetCode81SearchInRotatedSortedArrayII : BaseProblemClass
{
    public bool Search(int[] nums, int target)
    {
        int length = nums.Length;
        int rotationPoint = 0;
        int next = 0;
        int previous = 0;
        int begin = 0;
        int end = length - 1;
        int mid = 0;
        bool found = false;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            next = GetNext(nums, mid, length);
            if (next == mid)
                return nums[mid] == target;
            previous = GetPrevious(nums, mid, length);
            if (previous == mid)
                return nums[mid] == target;
            if (previous == next)
            {
                return target == nums[mid] || target == nums[next];
            }

            if (target == nums[mid])
                return true;
            if (nums[mid] < nums[previous] && nums[mid] < nums[next])
            {
                mid = GetNext(nums, previous, length);
                found = true;
                break;
            }

            if (nums[mid] > nums[length - 1])
            {
                begin = mid + 1;
                continue;
            }

            end = mid - 1;
        }

        if (!found)
        {
            previous = GetPrevious(nums, mid, length);
            next = GetNext(nums, mid, length);
            if (nums[mid] > nums[previous])
            {
                mid = previous;
            }
            else if (nums[mid] > nums[next])
            {
                mid = next;
            }
        }

        if (target == nums[mid])
            return true;
        if (mid != length - 1 && target > nums[mid] && target <= nums[length - 1])
        {
            begin = mid;
            end = length - 1;
            while (begin <= end)
            {
                mid = (begin + end) / 2;
                if (nums[mid] == target)
                    return true;
                if (nums[mid] > target)
                {
                    end = mid - 1;
                    continue;
                }

                begin = mid + 1;
            }

            return false;
        }

        if (mid == 0)
            return false;
        begin = 0;
        end = mid - 1;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] > target)
            {
                end = mid - 1;
                continue;
            }

            begin = mid + 1;
        }

        return false;
    }

    int GetPrevious(int[] nums, int index, int length)
    {
        int previous = index;
        while (nums[previous] == nums[index])
        {
            previous = GetPrevious(length, previous);
            if (previous == index)
                return index;
        }

        return previous;
    }

    int GetNext(int[] nums, int index, int length)
    {
        int next = index;
        while (nums[next] == nums[index])
        {
            next = GetNext(length, next);
            if (next == index)
                return index;
        }

        return next;
    }

    int GetNext(int length, int index)
    {
        return index < length - 1 ? index + 1 : 0;
    }

    int GetPrevious(int length, int index)
    {
        return index > 0 ? index - 1 : length - 1;
    }

    public override void Run()
    {
        int[] nums = [1];
        int target = 0;
        Console.WriteLine(Search(nums, target));
    }
}