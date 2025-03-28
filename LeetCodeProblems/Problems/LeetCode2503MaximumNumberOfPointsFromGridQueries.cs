namespace LeetCodeProblems.Problems;

public class LeetCode2503MaximumNumberOfPointsFromGridQueries
{
    public int[] MaxPoints(int[][] grid, int[] queries)
    {
        int m = grid.Length, n = grid[0].Length;
        var result = new int[queries.Length];

        List<(int row, int col)> directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];


        PriorityQueue<(int value, int row, int col), int> pq = new();
        pq.Enqueue((grid[0][0], 0, 0), grid[0][0]);


        var sortedQueries = new int[queries.Length][];
        for (int i = 0; i < queries.Length; i++)
        {
            sortedQueries[i] = [queries[i], i];
        }

        Array.Sort(sortedQueries, (a, b) => a[0] - b[0]);

        var visited = new bool[m, n];
        visited[0, 0] = true;

        var count = 0;
        Dictionary<int, int> queryResults = new();

        foreach (var q in sortedQueries)
        {
            var queryValue = q[0];

            while (pq.Count > 0 && pq.Peek().value < queryValue)
            {
                var (_, row, col) = pq.Dequeue();
                count++;

                foreach (var direction in directions)
                {
                    int newRow = row + direction.row, newCol = col + direction.col;
                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow, newCol])
                        continue;
                    visited[newRow, newCol] = true;
                    pq.Enqueue((grid[newRow][newCol], newRow, newCol), grid[newRow][newCol]);
                }
            }

            queryResults[queryValue] = count;
        }

        for (int i = 0; i < queries.Length; i++)
        {
            result[i] = queryResults[queries[i]];
        }

        return result;
    }
}