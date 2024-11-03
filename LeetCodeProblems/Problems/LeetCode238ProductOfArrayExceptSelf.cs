using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode238ProductOfArrayExceptSelf: BaseProblemClass
{
    public int[] ProductExceptSelf(int[] nums)
    {
        long product = 1;
        bool hasNoneZero = false;
        int zeroCount = 0;
        foreach (var n in nums)
        {
            if (n == 0)
            {
                zeroCount++;
                continue;
            }

            hasNoneZero = true;
            product *= n;
        }

        if (!hasNoneZero)
            product = 0;
        if (zeroCount > 1)
        {
            for (int i = 0, e = nums.Length; i < e; i++)
            {
                nums[i] = 0;
            }

            return nums;
        }

        for (int i = 0, e = nums.Length; i < e; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = (int) product;
                continue;
            }

            if (zeroCount>0)
            {
                nums[i] = 0;
                continue;
            }

            nums[i] = (int) (product / nums[i]);
        }

        return nums;
    }

    public override void Run()
    {
        int[] nums = [0, 4, 0];
        Console.WriteLine(JsonSerializer.Serialize(ProductExceptSelf(nums)) );
    }
}