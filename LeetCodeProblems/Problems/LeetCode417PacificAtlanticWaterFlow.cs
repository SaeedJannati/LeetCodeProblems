using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode417PacificAtlanticWaterFlow : BaseProblemClass
{
    #region My solution

    public IList<IList<int>> PacificAtlantic(int[][] heights)
    {
        int height = heights.Length;
        int width = heights[0].Length;
        var pacific = new bool[heights.Length, width];
        var atlantic = new bool[heights.Length, width];
        for (int i = 0; i < heights.Length; i++)
        {
            Dfs(heights, pacific, i, 0, height, width, int.MinValue);
            Dfs(heights, atlantic, i, width - 1, height, width, int.MinValue);
        }

        for (int i = 0; i < width; i++)
        {
            Dfs(heights, pacific, 0, i, height, width, int.MinValue);
            Dfs(heights, atlantic, height - 1, i, height, width, int.MinValue);
        }

        IList<IList<int>> result = [];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (!atlantic[i, j])
                    continue;
                if (!pacific[i, j])
                    continue;
                result.Add([i, j]);
            }
        }

        return result;
    }

    private void Dfs(int[][] heights, bool[,] ocean, int height, int width, int boardHeight, int boardWidth,
        int elevation)
    {
        if (height < 0 || height >= boardHeight)
            return;
        if (width < 0 || width >= boardWidth)
            return;
        if (ocean[height, width])
            return;
        if (heights[height][width] < elevation)
            return;
        ocean[height, width] = true;
        Dfs(heights, ocean, height, width + 1, boardHeight, boardWidth, heights[height][width]);
        Dfs(heights, ocean, height, width - 1, boardHeight, boardWidth, heights[height][width]);
        Dfs(heights, ocean, height + 1, width, boardHeight, boardWidth, heights[height][width]);
        Dfs(heights, ocean, height - 1, width, boardHeight, boardWidth, heights[height][width]);
    }

    #endregion

    #region Gpt solution

    // public IList<IList<int>> PacificAtlantic(int[][] heights)
    // {
    //     var result = new List<IList<int>>();
    //     int rows = heights.Length, cols = heights[0].Length;
    //
    //     var pacific = new bool[rows, cols];
    //     var atlantic = new bool[rows, cols];
    //     for (int i = 0; i < rows; i++)
    //     {
    //         Dfs(heights, pacific, int.MinValue, i, 0); 
    //         Dfs(heights, atlantic, int.MinValue, i, cols - 1); 
    //     }
    //     for (int j = 0; j < cols; j++)
    //     {
    //         Dfs(heights, pacific, int.MinValue, 0, j);
    //         Dfs(heights, atlantic, int.MinValue, rows - 1, j);
    //     }
    //     for (int i = 0; i < rows; i++)
    //     {
    //         for (int j = 0; j < cols; j++)
    //         {
    //             if (pacific[i, j] && atlantic[i, j])
    //                 result.Add(new List<int> { i, j });
    //         }
    //     }
    //
    //     return result;
    // }
    // private void Dfs(int[][] heights, bool[,] ocean, int prevHeight, int x, int y)
    // {
    //     int rows = heights.Length, cols = heights[0].Length;
    //     if (x < 0 || x >= rows || y < 0 || y >= cols) return;
    //     if (ocean[x, y] || heights[x][y] < prevHeight) return;
    //
    //     ocean[x, y] = true;
    //     Dfs(heights, ocean, heights[x][y], x + 1, y);
    //     Dfs(heights, ocean, heights[x][y], x - 1, y);
    //     Dfs(heights, ocean, heights[x][y], x, y + 1);
    //     Dfs(heights, ocean, heights[x][y], x, y - 1);
    // }

    #endregion


    public override void Run()
    {
        int[][] map =
        [
            [10, 10, 1, 11, 2, 15, 17, 6, 17, 10, 0, 10, 18, 9, 16, 13, 8, 9, 12, 6, 3, 2, 5, 19, 4, 14],
            [12, 19, 13, 2, 7, 2, 3, 8, 17, 4, 2, 1, 8, 13, 7, 2, 10, 16, 12, 3, 4, 12, 4, 16, 0, 12],
            [1, 12, 9, 18, 12, 16, 17, 5, 13, 0, 7, 13, 12, 13, 6, 2, 11, 19, 7, 2, 6, 11, 11, 0, 17, 6],
            [1, 12, 2, 0, 11, 7, 7, 3, 7, 13, 11, 1, 11, 15, 5, 13, 14, 12, 4, 10, 5, 16, 3, 17, 18, 12],
            [9, 16, 11, 5, 9, 13, 7, 18, 18, 14, 19, 10, 9, 4, 8, 14, 4, 19, 13, 1, 14, 8, 0, 3, 12, 10],
            [10, 19, 9, 11, 1, 18, 1, 2, 1, 8, 1, 5, 2, 15, 14, 13, 18, 18, 11, 4, 15, 3, 15, 12, 12, 2],
            [0, 10, 9, 2, 15, 9, 12, 7, 0, 0, 12, 18, 9, 12, 18, 4, 18, 10, 3, 1, 17, 14, 13, 18, 9, 4],
            [3, 19, 9, 16, 16, 19, 11, 19, 6, 9, 18, 0, 12, 11, 13, 1, 15, 6, 9, 18, 9, 6, 3, 12, 12, 2],
            [0, 16, 15, 12, 3, 19, 18, 9, 5, 1, 4, 3, 19, 15, 1, 0, 7, 10, 14, 4, 8, 10, 15, 16, 14, 8],
            [15, 9, 3, 15, 19, 17, 17, 10, 9, 8, 16, 11, 3, 15, 15, 9, 1, 14, 11, 13, 16, 7, 1, 7, 13, 5],
            [9, 19, 6, 7, 19, 14, 4, 18, 6, 10, 19, 13, 12, 7, 7, 15, 6, 10, 7, 8, 8, 8, 19, 13, 17, 14],
            [14, 7, 1, 15, 2, 6, 12, 4, 2, 19, 17, 17, 8, 9, 19, 10, 0, 12, 4, 12, 4, 16, 15, 18, 8, 0],
            [4, 8, 5, 8, 0, 2, 19, 18, 1, 7, 13, 9, 13, 16, 6, 15, 15, 12, 18, 5, 8, 11, 6, 17, 5, 11],
            [17, 16, 9, 19, 12, 6, 13, 19, 0, 6, 7, 9, 7, 13, 9, 18, 5, 15, 16, 8, 18, 9, 6, 0, 11, 14],
            [11, 5, 13, 3, 12, 19, 5, 15, 2, 15, 9, 16, 6, 12, 8, 0, 19, 19, 11, 0, 16, 8, 15, 15, 1, 12],
            [15, 16, 16, 19, 14, 1, 2, 11, 14, 8, 16, 13, 2, 0, 3, 8, 1, 5, 4, 15, 12, 5, 13, 3, 5, 3]
        ];
        Console.WriteLine(JsonSerializer.Serialize(PacificAtlantic(map)));
    }
}