using System.Text.Json;
using System.Xml;

namespace LeetCodeProblems.Problems;

public class LeetCode34FindFirstAndLastPositionOfElementInSortedArray : BaseProblemClass
{
    public int[] SearchRange(int[] nums, int target)
    {
        if (nums.Length == 0)
            return [-1, -1];
        if (nums.Length == 1)
            if (nums[0] == target)
                return [0, 0];
            else
                return [-1, -1];
        return [GetIndex(nums, target, true), GetIndex(nums, target, false)];
    }

    private int GetIndex(int[] nums, int target, bool findFirst)
    {
        int length = nums.Length - 1;
        int begin = 0;
        int end = length;
        int mid = 0;
        int newMid = 0;
        while (true)
        {
            mid = (end + begin) / 2;
            if (nums[mid] == target)
            {
                if (mid == 0 && findFirst)
                    return mid;
                if (mid == length && !findFirst)
                    return mid;
                if (findFirst && nums[mid - 1] < target)
                    return mid;
                if (!findFirst && nums[mid + 1] > target)
                    return mid;
                if (findFirst)
                    end = mid;
                else
                    begin = mid;
            }
            else if (nums[mid] > target)
            {
                end = mid;
            }
            else if(nums[mid] < target)
            {
                begin = mid;
            }

            newMid = (begin + end) / 2;
            if (newMid == mid)
            {
                if (nums[newMid] == target)
                {
                    if (newMid == 0 && findFirst)
                        return newMid;
                    if (newMid == length && !findFirst)
                        return newMid;
                    if (findFirst && nums[newMid - 1] < target)
                        return newMid;
                    if (!findFirst && nums[newMid + 1] > target)
                        return newMid;
                }
                if(mid<length)
                    newMid = mid + 1;
                if (nums[newMid] == target)
                {
                    if (newMid == 0 && findFirst)
                        return newMid;
                    if (newMid == length && !findFirst)
                        return newMid;
                    if (findFirst && nums[newMid - 1] < target)
                        return newMid;
                    if (!findFirst && nums[newMid + 1] > target)
                        return newMid;
                }
                if(mid>0)
                    newMid = mid - 1;
                if (nums[newMid] == target)
                {
                    if (newMid == 0 && findFirst)
                        return newMid;
                    if (newMid == length && !findFirst)
                        return newMid;
                    if (findFirst && nums[newMid - 1] < target)
                        return newMid;
                    if (!findFirst && nums[newMid + 1] > target)
                        return newMid;
                }
                return -1;
            }
        }
    }

    public override void Run()
    {
        int[] input = [0,0,0,0,0,1,1,2,2,3,4,4,5,5,5,5,6,7];
        int target = 0;
        Console.WriteLine(JsonSerializer.Serialize(SearchRange(input, target)));
    }
}