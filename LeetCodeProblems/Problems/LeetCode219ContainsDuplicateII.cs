namespace LeetCodeProblems.Problems;

public class LeetCode219ContainsDuplicateII: BaseProblemClass
{
    public bool ContainsNearbyDuplicate(int[] nums, int k)
    {
        if(k==0)
            return false;
        k++;
        HashSet<int> set = [];
        int length = nums.Length;
         int windowEnd=Math.Min(length, k);
        for (int i = 0; i <windowEnd; i++)
        {
            if (!set.Add(nums[i]))
                return true;

        }
        while (windowEnd < length)
        {
            set.Remove(nums[windowEnd-k]);
            if (!set.Add(nums[windowEnd]))
                return true;
            windowEnd++;
        }

        return false;
    }

    public override void Run()
    {
        int[] input = [1,2,3,1];
        int k = 3;
        Console.WriteLine(ContainsNearbyDuplicate(input, k));
    }
}