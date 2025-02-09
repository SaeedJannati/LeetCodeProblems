namespace LeetCodeProblems.Problems;

public class LeetCode2364CountNumberOfBadPairs: BaseProblemClass
{
    public long CountBadPairs(int[] nums)
    {
        Dictionary<int, int> diffCount = [];
        int length = nums.Length;
        int delta = 0;
        long goodPairs = 0;
        for (int i = 0; i < length; i++)
        {
            delta = nums[i] - i;
            diffCount.TryAdd(delta, 0);
            goodPairs += ++diffCount[delta] - 1;
        }
        return (long)length*(length-1)/2-goodPairs;
    }

    public override void Run()
    {
        int[] nums = [4, 1, 3, 3];
        Console.WriteLine(CountBadPairs(nums));
    }
}