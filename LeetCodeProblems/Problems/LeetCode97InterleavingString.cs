using System.Runtime.Intrinsics.X86;

namespace LeetCodeProblems.Problems;

public class LeetCode97InterleavingString : BaseProblemClass
{
    public bool IsInterleave(string s1, string s2, string s3)
    {
        if (s1.Length == 0)
            return s2 == s3;
        if (s2.Length == 0)
            return s1 == s3;
        if(s3.Length!=s1.Length+s2.Length)
            return false;
        int width = s2.Length;
        int height = s1.Length;
        List<List<bool>> dp = Enumerable
            .Range(0, height + 1)
            .Select(_ => new List<bool>()).ToList();
        dp[0].Add(true);
        for (int i = 0; i < height+1; i++)
        {
            for (int j = 0; j < width+1; j++)
            {
                if (i > 0)
                {
                    if (dp[i - 1][j])
                    {
                        if (s1[i-1] == s3[i + j-1])
                        {
                            dp[i].Add(true);
                            continue;
                        }
                    }
                }

                if (j > 0)
                {
                    if (dp[i][j - 1])
                    {
                        if (s2[j-1] == s3[i + j-1])
                        {
                            dp[i].Add(true);
                            continue;
                        }
                    }
                }
                if(i==0 && j==0)
                    continue;
                dp[i].Add(false);
            }
        }

        return dp[height][width];
    }

    public override void Run()
    {
        string s1 = "aa";
        string s2 = "ab";
        string s3 = "abaa";
        Console.WriteLine(IsInterleave(s1, s2, s3));
    }
}