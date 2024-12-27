namespace LeetCodeProblems.Problems;

public class LeetCode137SingleNumberII
{
    public int SingleNumber(int[] nums)
    {
        int length = nums.Length;
        HashSet<int> numsAppearedMoreThanOnce = new(length);
        HashSet<int> numsAppearedOnce = [];
        for (int i = 0; i < length; i++)
        {
            if(numsAppearedMoreThanOnce.Contains(nums[i]))
                continue;
            if (numsAppearedOnce.Contains(nums[i]))
            {
                numsAppearedMoreThanOnce.Add(nums[i]);
                numsAppearedOnce.Remove(nums[i]);
                continue;
            }
            numsAppearedOnce.Add(nums[i]);
        }

        return numsAppearedOnce.First();
    }
}