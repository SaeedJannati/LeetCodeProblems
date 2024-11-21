namespace LeetCodeProblems.Problems;

public class LeetCode221MaximalSquare
{
    public int MaximalSquare(char[][] matrix)
    {
        int height = matrix.Length;
        int width = matrix[0].Length;
        var dp = new int[height, width];
        int max = 0;
        for (int i = 0; i < height; i++)
        {
            dp[i, 0] = matrix[i][0]=='0'?0:1;
            if(dp[i,0]>max)
                max = dp[i,0];
        }

        for (int i = 0; i < width; i++)
        {
            dp[0, i] = matrix[0][i]=='0'?0:1;
            if(dp[0, i]>max)
                max = dp[0, i];
        }

        for (int i = 1; i < height; i++)
        {
            for (int j = 1; j < width; j++)
            {
                if (matrix[i][j] == '0')
                {
                    dp[i, j] =0;
                    continue;
                }

                dp[i, j] = (short)(Math.Min(Math.Min(dp[i, j - 1], dp[i - 1, j]), dp[i - 1, j - 1]) + 1);
                if(dp[i,j]>max)
                    max = dp[i,j];
            }
        }

        return max*max;
    }
}