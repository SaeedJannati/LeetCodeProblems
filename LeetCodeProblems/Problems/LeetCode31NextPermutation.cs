using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode31NextPermutation: BaseProblemClass
{
    public void NextPermutation(int[] nums)
    {
        int length = nums.Length;
        int temp = 0;
        for (int i = length - 1; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {
                int j = 0;
                for ( j = length - 1; j > i; j--)
                {
                    if(nums[j]>nums[i-1])
                        break;
                }

                temp = nums[i - 1];
                nums[i - 1] = nums[j];
                nums[j] = temp;
                for (int k = i,l=(length-i)/2+i; k <l  ; k++)
                {
                    temp = nums[k];
                    nums[k]=nums[length-k-1+i];
                    nums[length-k-1+i] = temp;
                }

                return;
            }
        }
        Array.Reverse(nums);
    }

    public override void Run()
    {
        int[] nums = [5,4,7,5,3,2];
        NextPermutation(nums);
        Console.WriteLine(JsonSerializer.Serialize(nums));
    }
}