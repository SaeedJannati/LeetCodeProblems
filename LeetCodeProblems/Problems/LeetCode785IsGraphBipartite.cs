namespace LeetCodeProblems.Problems;

public class LeetCode785IsGraphBipartite : BaseProblemClass
{
    #region Dfs colouring

    bool DfsColouring(int[][] graph, bool[] colours, bool[] visited, int node, bool colour)
    {
        visited[node] = true;
        colours[node] = colour;
        foreach (var vert in graph[node])
        {
            if (visited[vert])
            {
                if (colours[vert] == colour)
                    return false; 
                continue;
            }
            if (!DfsColouring(graph, colours, visited, vert, !colour))
                return false;
        }

        return true;
    }

    public bool IsBipartite(int[][] graph)
    {
        int length = graph.Length;
        bool[] visited = new bool[length];
        bool[] colours = new bool[length];
        for (int i = 0; i < length; i++)
        {
            if(visited[i])
                continue;
            if (!DfsColouring(graph, colours, visited, i, false))
                return false;
        }

        return true;
    }

    #endregion

    #region Union find

    // int Find(int[] parents, int first)
    // {
    //     if (parents[first] != first)
    //     {
    //         parents[first] = Find(parents, parents[first]);
    //     }
    //
    //     return parents[first];
    // }
    //
    // bool Union(int[] parents, int[] ranks, int first, int second)
    // {
    //     int firstParent = Find(parents, first);
    //     int secondParent = Find(parents, second);
    //     if (firstParent == secondParent)
    //         return false;
    //     if (ranks[firstParent] < ranks[secondParent])
    //     {
    //         parents[firstParent] = secondParent;
    //     }
    //     else if (ranks[firstParent] > ranks[secondParent])
    //     {
    //         parents[secondParent] = firstParent;
    //     }
    //     else
    //     {
    //         parents[secondParent] = firstParent;
    //         ranks[firstParent]++;
    //     }
    //
    //     return true;
    // }
    //
    // public bool IsBipartite(int[][] graph)
    // {
    //     int nodeCount = graph.Length;
    //     bool[] visited = new bool[nodeCount];
    //     int[] parents = Enumerable.Range(0, nodeCount).ToArray();
    //     int[] ranks = Enumerable.Repeat(1, nodeCount).ToArray();
    //     while (true)
    //     {
    //         var firstGroupRoot = -1;
    //         for (int i = 0; i < nodeCount; i++)
    //         {
    //             if (visited[i])
    //                 continue;
    //             if (graph[i].Length == 0)
    //                 continue;
    //             firstGroupRoot = i;
    //             break;
    //         }
    //
    //         if (firstGroupRoot == -1)
    //             return true;
    //         var secondGroupRoot = graph[firstGroupRoot][0];
    //         Queue<int> currentLayer = [];
    //         Queue<int> nextLayer = [];
    //         foreach (var vert in graph[firstGroupRoot])
    //         {
    //             visited[vert] = true;
    //             currentLayer.Enqueue(vert);
    //         }
    //
    //         int nextParent = secondGroupRoot;
    //         var node = 0;
    //         while (currentLayer.Count > 0)
    //         {
    //             while (currentLayer.Count > 0)
    //             {
    //                 node = currentLayer.Dequeue();
    //                 Union(parents, ranks, nextParent, node);
    //                 foreach (var vert in graph[node])
    //                 {
    //                     if (visited[vert])
    //                     {
    //                         if (Find(parents, vert) == nextParent)
    //                             return false;
    //                         continue;
    //                     }
    //
    //                     visited[vert] = true;
    //                     nextLayer.Enqueue(vert);
    //                 }
    //             }
    //
    //             nextParent = nextParent == firstGroupRoot ? secondGroupRoot : firstGroupRoot;
    //             while (nextLayer.Count > 0)
    //             {
    //                 currentLayer.Enqueue(nextLayer.Dequeue());
    //             }
    //         }
    //     }
    //
    //     return true;
    // }

    #endregion


    public override void Run()
    {
        int[][] graph = [[1,3],[0,2],[1,3],[0,2]];
        Console.WriteLine(IsBipartite(graph));
    }
}