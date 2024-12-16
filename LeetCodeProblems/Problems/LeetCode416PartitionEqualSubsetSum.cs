namespace LeetCodeProblems.Problems;

public class LeetCode416PartitionEqualSubsetSum: BaseProblemClass
{
    public bool CanPartition(int[] nums)
    {
        int max = int.MinValue;
        long sum = 0;
        int length = nums.Length;
        for (int i = 0; i < length; i++)
        {
            sum += nums[i];
            if (nums[i] > max)
                max = nums[i];
        }

        if (sum % 2 == 1)
            return false;
        long desiredWeight = sum / 2;
        if (max > desiredWeight)
            return false;
        if (max == desiredWeight)
            return true;
        int[,] dp = new int[length, desiredWeight + 1];
        for (int j = 1; j < desiredWeight + 1; j++)
        {
            if(nums[0]>j)
                continue;
            dp[0, j] = nums[0];
        }

        int ifAdd = 0;
        for (int i = 1; i < length; i++)
        {
            for (int j = 1; j < desiredWeight + 1; j++)
            {
                ifAdd = 0;
                if (j - nums[i] >= 0)
                    ifAdd = nums[i] + dp[i-1,j-nums[i]];
                if (ifAdd > j)
                    ifAdd = 0;
                dp[i,j]=Math.Max(ifAdd,dp[i-1,j]);
                if (dp[i, j] == desiredWeight)
                    return true;
            }
        }

        return false;
    }

    public override void Run()
    {
        int[] nums = [1,2,3,4,5,6,7];
        Console.WriteLine(CanPartition(nums));
    }
}