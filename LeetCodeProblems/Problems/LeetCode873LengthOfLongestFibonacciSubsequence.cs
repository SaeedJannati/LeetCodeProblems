namespace LeetCodeProblems.Problems;

public class LeetCode873LengthOfLongestFibonacciSubsequence
{
    public int LenLongestFibSubseq(int[] arr) {
        int length=arr.Length;
        int[,] dp=new int[length,length];
        Dictionary<int,int> reverseIndices=new Dictionary<int,int>();
        for (int i = 0; i < length; i++)
        {
            reverseIndices.Add(arr[i],i);
        }

        int maxLength = 0;
        for (int i = 0; i < length; i++)
        {
            for (int j =0; j < i; j++)
            {
                if(!reverseIndices.ContainsKey(arr[i]-arr[j]))
                    continue;
                int index=reverseIndices[arr[i]-arr[j]];
                if(index>=j)
                    continue;
                dp[j,i] = dp[index,j]>0?dp[index,j]+1:3;
                if(dp[j,i]>maxLength)
                    maxLength=dp[j,i];
            }
        }
        return maxLength>=3?maxLength : 0;
    }
}