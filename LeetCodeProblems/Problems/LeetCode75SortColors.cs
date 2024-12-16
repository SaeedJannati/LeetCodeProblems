using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode75SortColors: BaseProblemClass
{
    public void SortColors(int[] nums)
    {
        int length = nums.Length;
        int zeroPointer = 0;
        int twoPointer = length - 1;
        int temp = 0;
        for (int i = 0; i < length; i++)
        {
            if(i>twoPointer)
                return;
            switch (nums[i])
            {
                case 0:
                    if(i<zeroPointer)
                        continue;
                    temp=nums[zeroPointer];
                    nums[zeroPointer] = 0;
                    nums[i] = temp;
                    zeroPointer++;
                    if (nums[i] != 1)
                        i--;
                    break;
                case 2:
                    if(i>twoPointer)
                        break;
                    temp = nums[twoPointer];
                    nums[twoPointer] = 2;
                    nums[i] = temp;
                    twoPointer--;
                    if (nums[i] != 1)
                        i--;
                    break;
            }
        }
    }

    public override void Run()
    {
        int[] nums = [2,0,2,1,1,0];
        SortColors(nums);
        Console.WriteLine(JsonSerializer.Serialize(nums));
    }
}