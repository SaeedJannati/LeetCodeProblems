namespace LeetCodeProblems.Problems;

public class LeetCode547NumberofProvinces
{
    public int FindCircleNum(int[][] isConnected)
    {
        var length = isConnected.Length;
        var visited = new bool[length];
        Dictionary<int, List<int>> adjacencies = [];
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (isConnected[i][j] == 0)
                    continue;
                if (!adjacencies.TryGetValue(i, out var adjacent))
                {
                    adjacencies.Add(i, [j]);
                }
                else
                    adjacent.Add(j);

                if (!adjacencies.TryGetValue(j, out adjacent))
                {
                    adjacencies.Add(j, [i]);
                }
                else
                    adjacent.Add(i);
            }
        }

        int provinceCount = 0;
        for (int i = 0; i < length; i++)
        {
            if (visited[i])
                continue;
            provinceCount++;
            Dfs(adjacencies, i, visited);
        }

        return provinceCount;
    }

    void Dfs(Dictionary<int, List<int>> adjacencies, int key, bool[] visited)
    {
        if (visited[key])
            return;
        visited[key] = true;
        if (!adjacencies.TryGetValue(key, out var adjacent))
            return;
        adjacent.ForEach(i => Dfs(adjacencies, i, visited));
    }
}