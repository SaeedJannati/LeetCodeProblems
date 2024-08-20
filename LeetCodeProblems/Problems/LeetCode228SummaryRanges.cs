using System.Collections;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode228SummaryRanges : BaseProblemClass
{
    public override void Run()
    {
        int[] input = [];
        var outPut = SummaryRanges(input);
        Console.WriteLine(JsonSerializer.Serialize(outPut));
    }

    public IList<string> SummaryRanges(int[] nums)
    {
        if (nums.Length == 0)
            return [];
        IList<string> output = [];
        var initValue = nums[0];
        for (int i = 1, e = nums.Length; i < e; i++)
        {
            if (nums[i] - nums[i - 1] == 1)
                continue;
            if (nums[i - 1] == initValue)
            {
                output.Add($"{initValue}");
                initValue = nums[i];
                continue;
            }

            output.Add($"{initValue}->{nums[i - 1]}");
            initValue = nums[i];
        }
        output.Add(nums[^1] == initValue ? $"{initValue}" : $"{initValue}->{nums[^1]}");
        return output;
    }
}