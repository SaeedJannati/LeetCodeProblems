namespace LeetCodeProblems.Problems;

public class LeetCode200NumberOfIslands: BaseProblemClass
{
    public override void Run()
    {
        char[][] grid =
        [
            ['1', '1', '0', '0', '0'], ['1', '1', '0', '0', '0'], ['0', '0', '1', '0', '0'], ['0', '0', '0', '1', '1']
        ];
        
        Console.WriteLine(NumIslands(grid));
    }

    public int NumIslands(char[][] grid)
    {
        var islandCount = 0;
        var rows = grid.Length;
        var cols = grid[0].Length;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '0')
                    continue;
                SetVisited(grid, i, j);
                islandCount++;
            }
        }
        return islandCount;
    }

     void SetVisited(char[][] grid, int row, int col)
    {
        grid[row][col] = '0';
        if(row - 1 >= 0 && grid[row - 1][col] == '1')
            SetVisited(grid, row - 1, col);
        if(row+1<grid.Length && grid[row + 1][col] == '1')
            SetVisited(grid, row + 1, col);
        if(col - 1 >= 0 && grid[row][col - 1] == '1')
            SetVisited(grid, row, col - 1);
        if(col + 1 < grid[0].Length && grid[row][col + 1] == '1')
            SetVisited(grid, row, col + 1);
    }
}