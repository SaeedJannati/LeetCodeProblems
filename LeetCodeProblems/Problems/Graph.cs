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

    public List<int> GetTopologicalOrder()
    {
        List<int> outPut = new(adjacencyList.Count);
        Dictionary<int,int> inDegrees = new(adjacencyList.Count);
        HashSet<int> vertices = adjacencyList.Select(i=>i.Key).ToHashSet();
        foreach (var pair in adjacencyList)
        {
            foreach (var vertex in pair.Value)
            {
                if (inDegrees.ContainsKey(vertex))
                {
                    inDegrees[vertex]++;
                    continue;
                }
                inDegrees[vertex] = 1;
                vertices.Remove(vertex);
            }
        }

        if (vertices.Count == 0)
            return [];
        Queue<int> queue = new Queue<int>(adjacencyList.Count);
        foreach (var vertex in vertices)
        {
            queue.Enqueue(vertex);
        }

        int current = 0;
        while (queue.Count>0)
        {
            current = queue.Dequeue();
            outPut.Add(current);
            foreach (var vert in adjacencyList[current])
            {
                inDegrees[vert]--;
                if(inDegrees[vert] == 0)
                    queue.Enqueue(vert);
            }
        }

        
        return outPut;
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

    public static void RunTopologicalOrderSample()
    {
        
        var graph=new Graph();
        graph.AddEdge(1,2);
        graph.AddEdge(2,3);
        graph.AddEdge(6,3);
        graph.AddEdge(4,3);
        graph.AddEdge(3,5);
        graph.AddEdge(5,6);
        graph.AddEdge(5,1);
        graph.AddEdge(5,4);
        Console.WriteLine($"Direct cyclic graph:{JsonSerializer.Serialize(graph.GetTopologicalOrder())}");
        graph=new Graph();
        graph.AddEdge(1,2);
        graph.AddEdge(2,3);
        graph.AddEdge(6,3);
        graph.AddEdge(4,3);
        Console.WriteLine($"DAG:{JsonSerializer.Serialize(graph.GetTopologicalOrder())}");
    }

    public static void RunBfsDfsSample()
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