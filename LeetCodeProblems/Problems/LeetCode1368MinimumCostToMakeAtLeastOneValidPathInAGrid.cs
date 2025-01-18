namespace LeetCodeProblems.Problems;

public class LeetCode1368MinimumCostToMakeAtLeastOneValidPathInAGrid: BaseProblemClass
{
    public int MinCost(int[][] grid)
    {
        int height = grid.Length;
        int width = grid[0].Length;
        bool[][] visitedGrid = new bool[height][];
        for (int row = 0; row < height; row++)
        {
            visitedGrid[row] =new bool[width];
        }

        int desiredIndex = height * width-1;
        List<List<int>> directions = [[1, 0], [0, 1], [-1, 0], [0, -1]];
        int pathLength = 0;
        var currentLayer = new Queue<int>();
        var nextLayer = new Queue<int>();
        visitedGrid[0][0] = true;
        currentLayer.Enqueue(0);
        while (currentLayer.Count > 0)
        {
            while (currentLayer.Count > 0)
            {
                int index = currentLayer.Dequeue();
                if (index == desiredIndex)
                    return pathLength;
                int row = index / width;
                int col = index % width;
                var (directedRow, directedCol) = grid[row][col] switch
                {
                    1 => (row, col + 1),
                    2 => (row, col - 1),
                    3 => (row + 1, col),
                    4 => (row - 1, col),
                    _ => (0, 0)
                };
                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + directions[i][0];
                    if(newRow<0 || newRow >= height)
                        continue;
                    int newCol = col + directions[i][1];
                    if(newCol < 0 || newCol >= width)
                        continue;
                    int cellIndex=newRow*width + newCol;
                    
                    if (newRow == directedRow && newCol == directedCol)
                    {
                        if (!visitedGrid[newRow][newCol])
                        {
                            visitedGrid[newRow][newCol] = true;
                            currentLayer.Enqueue(cellIndex);
                        }

                        continue;
                    }
                    nextLayer.Enqueue(cellIndex);
                }
            }

            pathLength++;
            while (nextLayer.Count > 0)
            {
                int newIndex = nextLayer.Dequeue();
                int newRow=newIndex / width;
                int newCol = newIndex % width;
                if(visitedGrid[newRow][newCol])
                    continue;
                visitedGrid[newRow][newCol] = true;
                currentLayer.Enqueue(newIndex);
            }
        }

        return pathLength;
    }

    public override void Run()
    {
        int[][] grid = /*[[1, 1, 1, 1], [2, 2, 2, 2], [1, 1, 1, 1], [2, 2, 2, 2]];*/
        [[1,2],[4,3]];
        Console.WriteLine(MinCost(grid));
    }
}