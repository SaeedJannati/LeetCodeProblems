namespace LeetCodeProblems.Problems;

public class LeetCode217ContainsDuplicate
{
    public bool ContainsDuplicate(int[] nums)
    {
        HashSet<int> valeus = [];
        int length = nums.Length;
        for (int i = 0; i < length; i++)
        {
            if (!valeus.Add(nums[i]))
                return true;
        }

        return false;
    }
}