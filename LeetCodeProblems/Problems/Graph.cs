using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class Graph
{
    private Dictionary<int, List<int>> adjacencyList = [];

    public void AddVertex(int vertex)
    {
        if(adjacencyList.ContainsKey(vertex))
            return;
        adjacencyList.Add(vertex, []);
    }

    public void AddEdge(int firstVertex, int secondVertex)
    {
        AddVertex(firstVertex);
        AddVertex(secondVertex);
        adjacencyList[firstVertex].Add(secondVertex);
    }

    public List<int> BfsOrder()
    {
        List<int> order = [];
        HashSet<int> visited = [];
        
        Queue<int> vertices = [];
        int currentVertex = 0;
        foreach (var vertex in adjacencyList.Keys)
        {
           vertices.Enqueue(vertex);
           while (vertices.Count > 0)
           {
               currentVertex = vertices.Dequeue();
               if(!visited.Add(currentVertex))
                   continue;
               order.Add(currentVertex);
               foreach (var neighbor in adjacencyList[currentVertex])
               {
                   vertices.Enqueue(neighbor);
               }
           }
            
        }

        return order;
    }

    private void BfsRecursive()
    {
        
    }

    public List<int> DfsOrder()
    {
        List<int> order = [];
        HashSet<int> visited = [];
        foreach (var vertex in adjacencyList.Keys)
        {
            DfsRecursive(vertex, visited, order);
        }

        return order;
    }

    private void DfsRecursive(int vertex, HashSet<int> visited, List<int> order)
    {
        if(!visited.Add(vertex))
            return;
        order.Add(vertex);
        foreach (var neighbor in adjacencyList[vertex])
        {
            DfsRecursive(vertex, visited, order);
        }
    }

    public static void Sample()
    {
        var graph=new Graph();
        graph.AddEdge(1,2);
        graph.AddEdge(2,3);
        graph.AddEdge(3,4);
        graph.AddEdge(3,5);
        graph.AddEdge(1,6);
        graph.AddEdge(6,7);
        graph.AddEdge(1,8);
        graph.AddEdge(8,9);
        graph.AddEdge(8,10);
        graph.AddEdge(8,11);
        var dfsOrder=graph.DfsOrder();
        var bfsOrder=graph.BfsOrder();
        Console.WriteLine($"DFS:{JsonSerializer.Serialize(dfsOrder)}");
        Console.WriteLine($"BFS:{JsonSerializer.Serialize(bfsOrder)}");
    }
}