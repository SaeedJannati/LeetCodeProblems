namespace LeetCodeProblems.Problems;

public class LeetCode220ContainsDuplicateIII : BaseProblemClass
{
    public bool ContainsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff)
    {
        var sortedList = new SortedList<int, int>();
        int length = nums.Length;
        for (int i = 0,e=indexDiff+1<=length? indexDiff+1:length; i < e; i++)
        {
            if (sortedList.ContainsKey(nums[i]))
                return true;
            sortedList.Add(nums[i], 1);
        }

        int delta = 0;
        int? lastkey = null;
        foreach (var pair in sortedList)
        {
            if (lastkey is not null)
            {
                delta = int.Abs(lastkey.Value - pair.Key);
                if (delta <= valueDiff)
                    return true;
            }

            lastkey = pair.Key;
        }

        for (int i = indexDiff + 1; i < length; i++)
        {
            sortedList.Remove(nums[i - indexDiff - 1]);
            if (sortedList.ContainsKey(nums[i]))
            {
                return true;
            }

            var keys = sortedList.Keys;
            if (nums[i] > keys[^1])
            {
                if (int.Abs(nums[i] - keys[^1]) <= valueDiff)
                    return true;
                sortedList.Add(nums[i], 1);
                continue;
            }

            if (nums[i] < keys[0])
            {
                if (int.Abs(nums[i] - keys[0]) <= valueDiff)
                    return true;
                sortedList.Add(nums[i], 1);
                continue;
            }

            int begin = 0;
            int end = keys.Count;
            int mid = 0;
            while (begin <= end)
            {
                mid = (begin + end) / 2;
                if (nums[i] > keys[mid])
                {
                    begin = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }

            if (int.Abs(nums[i] - keys[mid]) <= valueDiff)
                return true;
            if (nums[i] < keys[mid])
            {
                if (mid > 0 && int.Abs(nums[i] - keys[mid - 1]) <= valueDiff)
                    return true;
            }
            else
            {
                if (mid < keys.Count - 1 && int.Abs(nums[i] - keys[mid + 1]) <= valueDiff)
                    return true;
            }

            sortedList.Add(nums[i], 1);
        }

        return false;
    }

    public override void Run()
    {
        int[] nums =
            // [1, 2, 3, 1];
            // [1, 5, 9, 1, 5, 9];
            [-2, 3];
        int indexDiff =
            // 3;
            // 2;
            2;

        int valueDiff =
            // 0;
            // 2;
            5;
        Console.WriteLine(ContainsNearbyAlmostDuplicate(nums, indexDiff, valueDiff));
    }
}