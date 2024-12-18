using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode239SlidingWindowMaximum: BaseProblemClass
{
    #region Order n

    public int[] MaxSlidingWindow(int[] nums, int k) {
        int length=nums.Length;
        int[] leftMax = new int[length];
        int[] rightMax = new int[length];
        leftMax[0]=nums[0];
        rightMax[length-1]=nums[length-1];
        int[] result = new int [length - k + 1];
        for (int i = 1; i < length; i++)
        {
            if (i % k == 0)
            {
                leftMax[i]=nums[i];
            }
            else
            {
                leftMax[i]=Math.Max(leftMax[i-1], nums[i]);
            }
            if ((length-i-1) % k == 0)
            {
                rightMax[length-1-i]=nums[length-1-i];
            }
            else
            {
                rightMax[length-1-i]=Math.Max(rightMax[length-i], nums[length-1-i]);
            }
        }

        for (int i = 0; i < length-k+1; i++)
        {
            result[i] = Math.Max(rightMax[i], leftMax[i + k-1]);
        }

        return result;
    }
    public override void Run()
    {
        int[] nums = [1,3,-1,-3,5,3,6,7];
        int k = 3;
        Console.WriteLine(JsonSerializer.Serialize(MaxSlidingWindow(nums, k)));
    }
    #endregion
    #region O nLog(k)

    // public int[] MaxSlidingWindow(int[] nums, int k)
    // {
    //     SortedDictionary<int, int> window = [];
    //     int length = nums.Length;
    //     if (window.Count == 0)
    //     {
    //         for (int i = 0; i < k; i++)
    //         {
    //             if (!window.TryAdd(-nums[i], 1))
    //                 window[-nums[i]]++;
    //         }
    //     }
    //
    //     int[] result = new int[length - k + 1];
    //     result[0] = -window.First().Key;
    //     int counter = 1;
    //     for (int i = k; i < length; i++)
    //     {
    //         window[-nums[i - k]]--;
    //         if(window[-nums[i - k]] == 0)
    //             window.Remove(-nums[i - k]);
    //         if (!window.TryAdd(-nums[i], 1))
    //             window[-nums[i]]++;
    //         result[counter] = -window.First().Key;
    //         counter++;
    //     }
    //
    //     return result;
    // }

    #endregion


}

