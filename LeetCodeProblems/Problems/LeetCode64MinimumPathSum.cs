namespace LeetCodeProblems.Problems;

public class LeetCode64MinimumPathSum: BaseProblemClass
{
    public int MinPathSum(int[][] grid)
    {
        if (grid.Length == 0)
            return 0;
        if(grid.Length == 1 && grid[0].Length==1)
            return grid[0][0];
        int minBefore = 0;
        int height=grid.Length;
        int width = grid[0].Length;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                minBefore = 0;
                if(i>0 && j>0)
                    minBefore=Math.Min(grid[i-1][j], grid[i][j-1]);
                else if(i>0)
                {
                    minBefore = grid[i - 1][j];
                }
                else if(j>0)
                {
                    minBefore = grid[i][j-1];
                }
                grid[i][j] += minBefore;
            }
        }

        return grid[height-1][width-1];
    }

    public override void Run()
    {
        int[][] input = [[1, 3, 1], [1, 5, 1], [4, 2, 1]];
        Console.WriteLine(MinPathSum(input));
    }
}