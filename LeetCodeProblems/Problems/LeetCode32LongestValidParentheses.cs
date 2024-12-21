namespace LeetCodeProblems.Problems;

public class LeetCode32LongestValidParentheses
{
    public int LongestValidParentheses(string s)
    {
        if (s.Length < 2)
            return 0;
        int length=s.Length;
        int[] dp=new int[length];
        for (int i = 0; i < length; i++)
        {
            dp[i]=s[i]=='('?1:-1;
        }

        int currentLength = 0;
        int maxLength = 0;
        
        for (int i = 0; i < length; i++)
        {
            for (int j = i+1; j < length; j++)
            {
                if (dp[i] < 0)
                {
                    break;
                }

                dp[i]+= s[j]=='('?1:-1;
                if (dp[i] == 0)
                {
                    if(j-i+1>maxLength) maxLength=j-i+1;
                }
            }
        }
        return maxLength;
    }
}