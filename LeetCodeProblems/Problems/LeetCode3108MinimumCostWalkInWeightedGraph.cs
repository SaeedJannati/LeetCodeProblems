using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode3108MinimumCostWalkInWeightedGraph : BaseProblemClass
{
    public int[] MinimumCost(int n, int[][] edges, int[][] query)
    {
        var parents = new int[n, 2];
        for (var i = 0; i < n; i++)
        {
            parents[i, 0] = i;
            parents[i, 1] = int.MaxValue;
        }

        var ranks = Enumerable.Repeat(0, n).ToArray();
        foreach (var edge in edges)
        {
            Union(ranks, parents, edge[0], edge[1], edge[2]);
        }

        for (int i = 0; i < n; i++)
            Find(i, parents);
        var queryLength = query.Length;
        var result = new int[queryLength];
        for (int i = 0, e = queryLength; i < e; i++)
        {
            if (parents[query[i][0], 0] != parents[query[i][1], 0])
            {
                result[i] = -1;
                continue;
            }

            result[i] = parents[Find(query[i][0], parents), 1];
        }

        return result;
    }

    int Find(int index, int[,] parents)
    {
        if (parents[index, 0] != index)
            parents[index, 0] = Find(parents[index, 0], parents);
        return parents[index, 0];
    }

    bool Union(int[] ranks, int[,] parents, int first, int second, int edgeValue)
    {
        var firstParent = Find(first, parents);
        var secondParent = Find(second, parents);
        if (firstParent == secondParent)
        {
            parents[firstParent, 1] &= edgeValue;
            return false;
        }

        if (ranks[firstParent] < ranks[secondParent])
        {
            parents[firstParent, 0] = secondParent;
            parents[secondParent, 1] &= edgeValue;
            parents[secondParent, 1] &= parents[firstParent, 1];
        }
        else if (ranks[firstParent] > ranks[secondParent])
        {
            parents[secondParent, 0] = firstParent;
            parents[firstParent, 1] &= edgeValue;
            parents[firstParent, 1] &= parents[secondParent, 1];
        }
        else
        {
            parents[secondParent, 0] = firstParent;
            parents[firstParent, 1] &= edgeValue;
            parents[firstParent, 1] &= parents[secondParent, 1];
            ranks[firstParent]++;
        }

        return true;
    }

    public override void Run()
    {
        int n = 7;
        // 6;
        int[][] edges = [[3, 0, 2], [5, 4, 12], [6, 3, 7], [4, 2, 2], [6, 2, 2]];
        // [[4, 5, 7], [3, 1, 7], [5, 2, 5], [1, 0, 0], [0, 4, 5], [3, 4, 8]];
        int[][] query = [[6, 0]];
        // [[4, 1], [5, 3], [1, 0], [0, 1], [1, 0], [0, 1], [5, 0], [3, 5]];
        Console.WriteLine(JsonSerializer.Serialize(MinimumCost(n, edges, query)));
    }
}