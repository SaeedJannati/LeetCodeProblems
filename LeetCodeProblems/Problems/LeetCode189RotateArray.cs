using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode189RotateArray : BaseProblemClass
{
    public void Rotate(int[] nums, int k)
    {
        if (nums.Length < 2)
            return;
        int length = nums.Length - 1;
        if (k % (length + 1) == 0)
            return;
        k %= length + 1;
        List<int> rotatedNums = new(length + 1);
        int newElement;
        for (int i = 0, e = length + 1; i < e; i++)
        {
            newElement = i - k;
            if (i - k >= 0)
            {
                rotatedNums.Add(nums[newElement]);
                continue;
            }

            if (newElement < -(length + 1))
                newElement %= (length + 1);
            rotatedNums.Add(nums[^-newElement]);
        }

        for (int i = 0, e = length + 1; i < e; i++)
        {
            nums[i] = rotatedNums[i];
        }
    }

    public override void Run()
    {
        int[] input = [1,2];
        int k = 5;
        Rotate(input, k);
        Console.WriteLine(JsonSerializer.Serialize(input));
    }
}