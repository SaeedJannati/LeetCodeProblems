namespace LeetCodeProblems.Problems;

public class LeetCode486PredictTheWinner: BaseProblemClass
{
    long CalcScore(int[] nums,long[] prefixSums,long[,]dp,int begin,int end)
    {
        if(dp[begin,end]!=0)
            return dp[begin,end];
        if (begin == end)
        {
            dp[begin,end] = nums[begin];
            return dp[begin,end];
        }

        if (end - begin == 1)
        {
            if (nums[begin] > nums[end])
            {
                dp[begin,end] = nums[begin];
                return dp[begin,end];
            }
            dp[begin,end] = nums[end];
            return dp[begin,end];
        }
        long elementsSum=prefixSums[end]-prefixSums[begin]+nums[begin];
        long score= elementsSum-CalcScore(nums,prefixSums,dp,begin+1,end);
        long otherScore = elementsSum-CalcScore(nums,prefixSums,dp,begin,end-1);
        dp[begin,end] = Math.Max(score, otherScore);
        return dp[begin,end];
    }

    public bool PredictTheWinner(int[] nums)
    {
      int length = nums.Length;
      long[,] dp = new long[length,length];
      long[] prefixSum = new long[length];
      prefixSum[0] = nums[0];
      for(int i=1;i<length;i++)
          prefixSum[i] = prefixSum[i-1]+nums[i];
      long firstPlayerScore=CalcScore(nums,prefixSum,dp,0,length-1);
   
      var secondPlayerScore=prefixSum[length-1]-firstPlayerScore;
      return firstPlayerScore >= secondPlayerScore;
    }

    public override void Run()
    {
        int[] nums = [1, 5, 2];
        Console.WriteLine(PredictTheWinner(nums));
    }
}