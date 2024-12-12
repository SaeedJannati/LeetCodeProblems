namespace LeetCodeProblems.Problems;

public class LeetCode347TopKFrequentElements
{
    public int[] TopKFrequent(int[] nums, int k)
    {
        Dictionary<int, int> occurrences = [];
        int length = nums.Length;
        for (int i = 0; i < length; i++)
        {
            if (occurrences.TryGetValue(nums[i], out var value))
                occurrences[nums[i]] = ++value;
            else
                occurrences[nums[i]] = 1;
        }

        PriorityQueue<int, int> heap = new(occurrences.Count);
        foreach (var pair in occurrences)
        {
            heap.Enqueue(pair.Key, -pair.Value);
        }

        var result = new int[k];
        for (int i = 0; i < k; i++)
        {
            result[i]= heap.Dequeue();
        }
        return result;
    }
}