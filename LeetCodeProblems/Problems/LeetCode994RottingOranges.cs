namespace LeetCodeProblems.Problems;

public class LeetCode994RottingOranges : BaseProblemClass
{
    public int OrangesRotting(int[][] grid)
    {
        List<List<int>> directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        Queue<(int row, int column)> currentLayer = new();
        Queue<(int row, int column)> nextLayer = new();
        int height = grid.Length;
        int width = grid[0].Length;
        HashSet<int> goodOranges = new();
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                switch (grid[i][j])
                {
                    case 0:
                        continue;
                    case 1:
                        goodOranges.Add(i * width + j);
                        break;
                    case 2:
                        currentLayer.Enqueue((i, j));
                        break;
                }
            }
        }

        int minutesPassed = 0;
        (int row, int column) coord = new();
        while (currentLayer.Count > 0)
        {
            while (currentLayer.Count > 0)
            {
                coord = currentLayer.Dequeue();
                var neighbors = GetNeighboursWithGoodOrange(height, width, coord.row, coord.column, directions, grid);
                neighbors.ForEach(n =>
                {
                    grid[n[0]][n[1]] = 2;
                    goodOranges.Remove(n[0] * width + n[1]);
                    nextLayer.Enqueue((n[0], n[1]));
                });
            }

            if (nextLayer.Count == 0)
                continue;
            minutesPassed++;
            while (nextLayer.Count > 0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }
        }

        if (goodOranges.Count > 0)
            return -1;
        return minutesPassed;
    }

    List<List<int>> GetNeighboursWithGoodOrange(int height, int width, int row, int col, List<List<int>> directions,
        int[][] grid)
    {
        List<List<int>> neighbours = new(4);
        int neighbourRow = 0;
        int neighbourCol = 0;
        foreach (var direction in directions)
        {
            neighbourRow = row + direction[0];
            neighbourCol = col + direction[1];
            if (neighbourRow >= height || neighbourCol >= width)
                continue;
            if (neighbourRow < 0 || neighbourCol < 0)
                continue;
            if (grid[neighbourRow][neighbourCol] != 1)
                continue;
            neighbours.Add([neighbourRow, neighbourCol]);
        }

        return neighbours;
    }

    public override void Run()
    {
        int[][] grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]];
        var minutes = OrangesRotting(grid);
        Console.WriteLine(minutes);
    }
}