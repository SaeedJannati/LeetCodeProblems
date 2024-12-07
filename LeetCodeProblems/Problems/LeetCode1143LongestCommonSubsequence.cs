namespace LeetCodeProblems.Problems;

public class LeetCode1143LongestCommonSubsequence
{
    public int LongestCommonSubsequence(string text1, string text2)
    {
        if (text1.Length == 0 || text2.Length == 0)
            return 0;
        var length1 = text1.Length;
        var length2 = text2.Length;
        var dp = new int[length1, length2];
        dp[0, 0] = text1[0] == text2[0] ? 1 : 0;
        for (int i = 1; i < length1; i++)
        {
            if (dp[i - 1, 0] == 1)
            {
                dp[i, 0] = 1;
                continue;
            }
            dp[i, 0] = text1[i]==text2[0]?1:0;
        }

        for (int i = 1; i < length2; i++)
        {
            if (dp[0, i-1] == 1)
            {
                dp[0, i] = 1;
                continue;
            }
            dp[0,i]= text1[0]==text2[i]?1:0;
        }

        for (int i = 1; i < length1; i++)
        {
            for (int j = 1; j < length2; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i, j] = dp[i - 1, j - 1] + 1;
                    continue;
                }
                dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
            }
        }
        return dp[length1-1, length2-1];
    }
}