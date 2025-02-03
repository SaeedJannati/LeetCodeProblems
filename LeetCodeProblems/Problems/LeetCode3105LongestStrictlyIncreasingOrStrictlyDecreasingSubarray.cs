namespace LeetCodeProblems.Problems;

public class LeetCode3105LongestStrictlyIncreasingOrStrictlyDecreasingSubarray: BaseProblemClass
{
    public int LongestMonotonicSubarray(int[] nums)
    {
        int currentStreak = 0;
        int maxStreak = 1;
        int minStreak = -1;
        int length = nums.Length;
        for (int i = 1; i < length; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                if (currentStreak <= 0)
                {
                    currentStreak = 2;
                }
                else
                {
                    currentStreak++;
                }

                if (maxStreak < currentStreak)
                    maxStreak = currentStreak;
            }

            if (nums[i] < nums[i - 1])
            {
                if (currentStreak >= 0)
                {
                    currentStreak = -2;
                }
                else
                {
                    currentStreak--;
                }

                if (currentStreak < minStreak)
                    minStreak = currentStreak;
            }

            if (nums[i] == nums[i - 1])
                currentStreak = 0;
        }

        return int.Max(-minStreak, maxStreak);
    }

    public override void Run()
    {
        int[] nums = [1, 4, 3, 3, 2];
        Console.WriteLine(LongestMonotonicSubarray(nums));
    }
}