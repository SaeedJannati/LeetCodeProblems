using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class GeekForGeekTopologicalsort : BaseProblemClass
{
    #region Without cycle detection

    public List<int> topologicalSort(List<List<int>> adj)
    {
        Stack<int> topoStack = new Stack<int>(adj.Count);
        bool[] visited = new bool[adj.Count];
        for (int i = 0; i < adj.Count; i++)
        {
            ToplogicalSort(adj, visited, topoStack, i);
        }

        List<int> result = new List<int>(adj.Count);
        while (topoStack.Count > 0)
        {
            result.Add(topoStack.Pop());
        }

        return result;
    }

    void ToplogicalSort(List<List<int>> adj, bool[] visited, Stack<int> topoStack, int node)
    {
        if (visited[node])
            return;
        visited[node] = true;
        foreach (var num in adj[node])
        {
            ToplogicalSort(adj, visited, topoStack, num);
        }

        topoStack.Push(node);
    }

    #endregion

    #region With Cycle detection

    // public List<int> topologicalSort(List<List<int>> adj)
    // {
    //     Stack<int> topoStack = new Stack<int>(adj.Count);
    //     // 0==> not visited, 1==> visiting , 2==>visited
    //     int[] visited = new int[adj.Count];
    //     for (int i = 0; i < adj.Count; i++)
    //     {
    //         if (!ToplogicalSort(adj, visited, topoStack, i))
    //         {
    //             Console.WriteLine("Cycle Detected");
    //             return [];
    //         }
    //
    //         
    //     }
    //
    //     List<int> result = new List<int>(adj.Count);
    //     while (topoStack.Count > 0)
    //     {
    //         result.Add(topoStack.Pop());
    //     }
    //
    //     return result;
    // }
    //
    // bool ToplogicalSort(List<List<int>> adj, int[] visited, Stack<int> topoStack, int node)
    // {
    //     if (visited[node] == 2)
    //         return true;
    //     visited[node] = 1;
    //     foreach (var num in adj[node])
    //     {
    //         if (visited[num] == 1)
    //             return false;
    //         if (!ToplogicalSort(adj, visited, topoStack, num))
    //             return false;
    //     }
    //
    //     visited[node] = 2;
    //     topoStack.Push(node);
    //     return true;
    // }

    #endregion

    public override void Run()
    {
        List<List<int>> adj = [[], [3], [3], [], [0, 1], [0, 2]];
        Console.WriteLine(JsonSerializer.Serialize(topologicalSort(adj)));
    }
}