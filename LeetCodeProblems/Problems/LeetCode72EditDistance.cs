namespace LeetCodeProblems.Problems;

public class LeetCode72EditDistance: BaseProblemClass
{
    public int MinDistance(string word1, string word2)
    {
        if(word1.Length==0)
            return word2.Length;
        if(word2.Length==0)
            return word1.Length;
        if (word1 == word2)
            return 0;
        var height= word1.Length+1;
        var width= word2.Length+1;
        var dp=new int[height,width];
        for (int i = 0; i < height; i++)
        {
            dp[i, 0] = i;
        }

        for (int i = 0; i < width; i++)
        {
            dp[0, i] = i;
        }

        for (var i = 1; i < height; i++)
        {
            for (var j = 1; j < width; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i, j] = Math.Min(dp[i - 1, j - 1], Math.Min(dp[i - 1, j] + 1, dp[i, j - 1] + 1));
                    continue;
                }
                dp[i,j]=Math.Min(dp[i - 1, j - 1]+1, Math.Min(dp[i - 1, j] + 1, dp[i, j - 1] + 1));
            }
        }

        return dp[height-1,width-1];
    }

    public override void Run()
    {
        var word1 = "a";
        var word2 = "ab";
        Console.WriteLine(MinDistance(word1, word2));
    }
}