namespace LeetCodeProblems.Problems;

public class LeetCode63UniquePathsII: BaseProblemClass
{
    public int UniquePathsWithObstacles(int[][] obstacleGrid)
    {
        var height = obstacleGrid.Length;
        var width = obstacleGrid[0].Length;
        if (obstacleGrid[height - 1][width - 1] == 1)
            return 0;
        for (int i = 0; i <width; i++)
        {
            if(obstacleGrid[0][i]==1)
                break;
            obstacleGrid[0][i] = -1;
        }
        for (int i = 0; i <height; i++)
        {
            if(obstacleGrid[i][0]==1)
                break;
            obstacleGrid[i][0] = -1;
        }

        for (int i = 1; i < height; i++)
        {
            for (int j = 1; j < width; j++)
            {
                if(obstacleGrid[i][j]==1)
                    continue;
                obstacleGrid[i][j] = Math.Min(0, obstacleGrid[i-1][j])+Math.Min(0, obstacleGrid[i][j-1]);
            }
        }
        return  -obstacleGrid[height-1][width-1];
    }

    public override void Run()
    {
        int[][] input = [[0, 0], [1, 1], [0, 0]];
        Console.WriteLine(UniquePathsWithObstacles(input));
    }
}