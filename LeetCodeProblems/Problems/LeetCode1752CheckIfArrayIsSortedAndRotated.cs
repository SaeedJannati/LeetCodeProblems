namespace LeetCodeProblems.Problems;

public class LeetCode1752CheckIfArrayIsSortedAndRotated: BaseProblemClass
{
    public bool Check(int[] nums) {
        int length=nums.Length;
        if(length <3)
            return true;
        int previous = 0;
        bool hasRotated = false;
        for (int i = 1; i < length; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if(hasRotated)
                    return false;
                if(nums[i]>nums[0])
                    return false;
                hasRotated = true;
                continue;
            }

            if (hasRotated)
            {
                if(nums[i]>nums[0])
                    return false;
            }
        }

        return true;


    }

    public override void Run()
    {
        int[] nums = [1, 3, 2];
        Console.WriteLine(Check(nums));
    }
}