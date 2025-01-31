namespace LeetCodeProblems.Problems;

public class LeetCode827MakingALargeIsland : BaseProblemClass
{
    int Find(int index, int[] parents)
    {
        if (parents[index] != index)
            parents[index] = Find(index, parents);
        return parents[index];
    }

    bool Union(int[] ranks, int[] parents, int first, int second)
    {
        int firstRoot = Find(first, parents);
        int secondRoot = Find(second, parents);
        if (firstRoot == secondRoot)
            return false;
        if (ranks[secondRoot] > ranks[firstRoot])
        {
            parents[firstRoot] = secondRoot;
            ranks[secondRoot] += ranks[firstRoot];
        }
        else
        {
            parents[secondRoot] = firstRoot;
            ranks[firstRoot] += ranks[secondRoot];
        }

        return true;
    }

    void Dfs(int[][] grid, int[] ranks, int[] parents, int[] visited, List<List<int>> directions, int side, int row,
        int col, int parent, int index)
    {
        if (grid[row][col] == 0)
        {
            ranks[index] = 0;
            return;
        }

        if (parent != -1)
        {
            Union(ranks, parents, parent, index);
        }
        else
        {
            parent = index;
        }

        foreach (var direction in directions)
        {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            if (newRow < 0 || newRow >= side || newCol < 0 || newCol >= side)
                continue;
            index = newRow * side + newCol;
            if (visited[index] == 1)
                continue;
            visited[index] = 1;
            Dfs(grid, ranks, parents, visited, directions, side, newRow, newCol, parent, index);
        }
    }

    public int LargestIsland(int[][] grid)
    {
        int side = grid.Length;
        int[] parents = Enumerable.Range(0, side * side).ToArray();
        int[] ranks = Enumerable.Repeat(1, side * side).ToArray();
        int[] visited = new int[side * side];
        List<List<int>> directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        int index = 0;
        for (int i = 0; i < side; i++)
        {
            for (int j = 0; j < side; j++)
            {
                index = i * side + j;
                if (visited[index] == 1)
                    continue;
                visited[index] = 1;
                if (grid[i][j] == 0)
                {
                    ranks[index] = 0;
                    continue;
                }

                Dfs(grid, ranks, parents, visited, directions, side, i, j, -1, index);
            }
        }

        int maxIslandSize = 0;
        int currentIslandSize = 0;
        int row = 0;
        int col = 0;
        HashSet<int> neighborParents = [];
        for (int i = 0; i < side; i++)
        {
            for (int j = 0; j < side; j++)
            {
                if (grid[i][j] != 0)
                    continue;
                neighborParents = [];
                currentIslandSize = 1;
                foreach (var direction in directions)
                {
                    row = i + direction[0];
                    if (row < 0 || row >= side)
                        continue;
                    col = j + direction[1];
                    if (col < 0 || col >= side)
                        continue;
                    index = row * side + col;
                    neighborParents.Add(parents[index]);
                }

                foreach (var node in neighborParents)
                {
                    currentIslandSize += ranks[node];
                }

                if (currentIslandSize > maxIslandSize)
                    maxIslandSize = currentIslandSize;
            }
        }

        if (maxIslandSize == 0)
            return side * side;
        return maxIslandSize;
    }

    public override void Run()
    {
        int[][] grid = [[0, 1], [0, 1]];
        Console.WriteLine(LargestIsland(grid));
    }
}