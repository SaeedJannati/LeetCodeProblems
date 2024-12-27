using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode27RemoveElement: BaseProblemClass
{
    public int RemoveElement(int[] nums, int val)
    {
        var secondPointer = nums.Length - 1;
       
        int temp;
        for (int i = 0, e = nums.Length; i < e; i++)
        {
            if (nums[i] != val) continue;
            while (nums[secondPointer] == val && secondPointer > i)
            {
                secondPointer--;
            }
            if (secondPointer == i)
                break;
            temp = nums[secondPointer];
            nums[secondPointer] = val;
            nums[i] = temp;
        }
        return nums.Count(i=>i!=val);
    }

    public override void Run()
    {
        int[] input = [0,1,2,2,3,0,4,2];
        var outPut= RemoveElement(input, 2);
        Console.WriteLine($"{JsonSerializer.Serialize(input)},{outPut}");
    }
}