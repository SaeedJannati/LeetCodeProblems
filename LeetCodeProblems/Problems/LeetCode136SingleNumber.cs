namespace LeetCodeProblems.Problems;

public class LeetCode136SingleNumber : BaseProblemClass
{
    public int SingleNumber(int[] nums)
    {
        var result = nums[0];
        for (int i = 1, e = nums.Length; i < e; i++)
        {
            result ^= nums[i];
        }

        return result;
    }

    public override void Run()
    {
    }
}