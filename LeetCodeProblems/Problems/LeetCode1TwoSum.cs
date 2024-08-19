using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode1TwoSum : BaseProblemClass
{
    private int[] TwoSum(int[] nums, int target)
    {
        var numSet = new Dictionary<int, int>(nums.Length);
        for (int i = 0, e = nums.Length; i < e; i++)
        {
            if (numSet.ContainsKey(nums[i]))
                continue;
            numSet[nums[i]] = i;
        }

        for (int i = 0, e = nums.Length; i < e; i++)
        {
            if (numSet.ContainsKey(target - nums[i]) && numSet[target - nums[i]] != i)
                return [i, numSet[target - nums[i]]];
        }

        return [];
    }

    public override void Run()
    {
        int[] input = [3, 2, 4];
        int target = 6;
        var outPut = TwoSum(input, target);
        Console.WriteLine(JsonSerializer.Serialize(outPut, new JsonSerializerOptions {WriteIndented = true}));
    }
}