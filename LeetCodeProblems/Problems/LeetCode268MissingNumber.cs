namespace LeetCodeProblems.Problems;

public class LeetCode268MissingNumber: BaseProblemClass
{
    public int MissingNumber(int[] nums)
    {
        int secondIndex = 0;
        int length = nums.Length;
        for (int i = 0; i < length; i++)
        {
            if(nums[i]==i)
                continue;
            if(nums[i]==length)
                continue;
            secondIndex = nums[nums[i]];
            (nums[i],nums[nums[i]]) = (nums[nums[i]],nums[i]);
            if (secondIndex < i)
                i--;
        }

        for (int i = 0; i < length; i++)
        {
            if (nums[i] != i)
                return i;
        }

        return length;
    }

    public override void Run()
    {
        int[] nums = [3, 0, 1];
        Console.WriteLine(MissingNumber(nums));
    }
}