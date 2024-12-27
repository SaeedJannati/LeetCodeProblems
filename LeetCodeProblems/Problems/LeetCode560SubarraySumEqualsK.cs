namespace LeetCodeProblems.Problems;

public class LeetCode560SubarraySumEqualsK: BaseProblemClass
{
    public int SubarraySum(int[] nums, int k) {
     
        int length=nums.Length;
        Dictionary<int, int> prefixes = new(length + 1);
        prefixes[0] = 1;
        int output = 0;
        int currnetSum = 0;
        for (int i = 0; i < length; i++)
        {
            currnetSum += nums[i];
            if(prefixes.TryGetValue(currnetSum-k,out var count))
                output+=count;
            if(!prefixes.TryAdd(currnetSum, 1))
                prefixes[currnetSum]++;
        }
        return output;
    }
    


    public override void Run()
    {
        int[] nums = [1,1,1];
        int k = 2;
        Console.WriteLine(SubarraySum(nums, k));
    }

    #region Brute force O(n^2) better than the lower one though
    // public int SubarraySum(int[] nums, int k)
    // {
    //     int result = 0;
    //     int sum = 0;
    //     int length = nums.Length;
    //     for (int i = 0; i < length; i++)
    //     {
    //         sum = 0;
    //         for (int j = i ; j < length; j++)
    //         {
    //             sum += nums[j];
    //             if(sum == k)
    //                 result++;
    //         }
    //     }
    //
    //     return result;
    // }
    

    #endregion
    #region  O(n^2)

    // public int SubarraySum(int[] nums, int k)
    // {
    //     int length = nums.Length;
    //     List<long> prefixSums = new(length+1);
    //     prefixSums.Add(0);
    //     for (int i = 1; i <= length; i++)
    //     {
    //         prefixSums.Add(prefixSums[^1] + nums[i-1]);
    //     }
    //
    //     int subarrayCount = 0;
    //     for (int i = 0; i < length+1; i++)
    //     {
    //         for (int j = i+1; j < length+1; j++)
    //         {
    //             if(prefixSums[j]-prefixSums[i]==k)
    //                 subarrayCount++;
    //         }
    //     }
    //     return subarrayCount;
    // }

    #endregion
}