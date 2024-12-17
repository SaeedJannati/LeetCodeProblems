namespace LeetCodeProblems.Problems;

public class LeetCode239SlidingWindowMaximum
{
    public int[] MaxSlidingWindow(int[] nums, int k)
    {
        SortedDictionary<int, int> window = [];
        int length = nums.Length;
        if (window.Count == 0)
        {
            for (int i = 0; i < k; i++)
            {
                if (!window.TryAdd(-nums[i], 1))
                    window[-nums[i]]++;
            }
        }

        int[] result = new int[length - k + 1];
        result[0] = -window.First().Key;
        int counter = 1;
        for (int i = k; i < length; i++)
        {
            window[-nums[i - k]]--;
            if(window[-nums[i - k]] == 0)
                window.Remove(-nums[i - k]);
            if (!window.TryAdd(-nums[i], 1))
                window[-nums[i]]++;
            result[counter] = -window.First().Key;
            counter++;
        }

        return result;
    }
}