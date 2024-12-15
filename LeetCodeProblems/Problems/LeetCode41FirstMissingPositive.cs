namespace LeetCodeProblems.Problems;

public class LeetCode41FirstMissingPositive: BaseProblemClass
{
    public int FirstMissingPositive(int[] nums)
    {
        int temp = 0;
        int length = nums.Length;
        for (int i = 0; i < length; i++)
        {
            if (nums[i] <= 0)
                continue;
            if (nums[i] > length)
                continue;
            if(nums[i]==i+1)
                continue;
            temp = nums[nums[i] - 1];
            if(temp==nums[i])
                continue;
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
            if (nums[i] > 0 && nums[i]!=i+1)
                i--;
        }
        for (int i = 0; i < length; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return length + 1;
    }

    public override void Run()
    {
        int[] nums = [-3,9,16,4,5,16,-4,9,26,2,1,19,-1,25,7,22,2,-7,14,2,5,-6,1,17,3,24,-4,17,15];
        Console.WriteLine(FirstMissingPositive(nums));
    }
}