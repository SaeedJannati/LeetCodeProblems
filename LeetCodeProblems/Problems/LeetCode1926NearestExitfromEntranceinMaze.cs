namespace LeetCodeProblems.Problems;

public class LeetCode1926NearestExitfromEntranceinMaze: BaseProblemClass
{
    public int NearestExit(char[][] maze, int[] entrance)
    {
        bool[,] visited = new bool[maze.Length, maze[0].Length];
        int height = maze.Length;
        int width = maze[0].Length;
        Queue<(int row, int col)> currentLayer = new();
        Queue<(int row, int col)> nextLayer = new();
        int pathLength = 0;
        visited[entrance[0], entrance[1]] = true;
        var neighbors = GetNeighbours(maze, visited, entrance[0], entrance[1]);
        neighbors.ForEach(i =>
        {
            visited[i.height, i.width] = true;
            currentLayer.Enqueue(i);
        });
        (int row, int col) currentCoord = default;
        while (currentLayer.Count > 0)
        {
            pathLength++;
            while (currentLayer.Count > 0)
            {
                currentCoord = currentLayer.Dequeue();
                if (IsEdge(currentCoord.row, currentCoord.col, height, width))
                    return pathLength;
                visited[currentCoord.row, currentCoord.col] = true;
                neighbors = GetNeighbours(maze, visited, currentCoord.row, currentCoord.col);
                foreach (var neighbor in neighbors)
                {
                    visited[neighbor.height, neighbor.width] = true;
                    nextLayer.Enqueue(neighbor);
                }

            
            }

            while (nextLayer.Count > 0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }
        }

        return -1;
    }

    List<(int height, int width)> GetNeighbours(char[][] maze, bool[,] visited, int row, int col)
    {
        List<(int height, int width)> directions =
        [
            (height: 1, width: 0),
            (height: -1, width: 0),
            (height: 0, width: 1),
            (height: 0, width: -1)
        ];
        int height = maze.Length;
        int width = maze[0].Length;
        return directions
            .Where(d => IsInBound(row + d.height, col +d.width, height, width))
            .Where(d => !visited[row + d.height, col + d.width])
            .Where(d => maze[row + d.height][col + d.width] == '.')
            .Select(d => (row +d.height, col +d.width)).ToList();
    }

    bool IsInBound(int row, int col, int height, int width)
    {
        return col >= 0 && col < width && row >= 0 && row < height;
    }

    bool IsEdge(int row, int col, int height, int width)
    {
        return row == 0 || col == 0 || row == height - 1 || col == width - 1;
    }

    public override void Run()
    {
        char[][] maze =[['+','.','+','+','+','+','+'],['+','.','+','.','.','.','+'],['+','.','+','.','+','.','+'],['+','.','.','.','+','.','+'],['+','+','+','+','+','.','+']] ;
        int[] entrance = [0,1];
        var length=NearestExit(maze, entrance);
        Console.WriteLine(length);
    }
}