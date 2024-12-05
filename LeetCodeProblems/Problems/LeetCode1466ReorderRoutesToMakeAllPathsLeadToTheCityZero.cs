namespace LeetCodeProblems.Problems;

public class LeetCode1466ReorderRoutesToMakeAllPathsLeadToTheCityZero : BaseProblemClass
{
    public override void Run()
    {
        int[][] connections = [[0, 1], [1, 3], [2, 3], [4, 0], [4, 5]];
        int n = 6;
        Console.WriteLine(MinReorder(n, connections));
    }

    #region Bfs

    public int MinReorder(int n, int[][] connections)
    {
        Dictionary<int,Dictionary<int,int>> edges = new (n);
        foreach (var connection in connections)
        {
            if (edges.TryGetValue(connection[1], out var values))
            {
                values[connection[0]]=0;
            }
            else
            {
                edges[connection[1]] =[];
                edges[connection[1]][connection[0]] = 0;
            }
            if (edges.TryGetValue(connection[0], out  values))
            {
                values[connection[1]]=1;
            }
            else
            {
                edges[connection[0]] = new Dictionary<int, int>
                {
                    [connection[1]] = 1
                };
            }
           
        }

        int changes = 0;
        Queue<int> nodesToVisit = new();
        nodesToVisit.Enqueue(0);
        int current = 0;
        HashSet<int> visited = new(n) { current };
        while (nodesToVisit.Count>0)
        {
            current = nodesToVisit.Dequeue();
            var nodes=edges[current];
            foreach (var node in nodes)
            {
                if(!visited.Add(node.Key))
                    continue;
                changes+=node.Value;
                nodesToVisit.Enqueue(node.Key);
            }
        }

        return changes;
    }

    #endregion
   
    #region Dfs
    // public int MinReorder(int n, int[][] connections)
    // {
    //     Dictionary<int, HashSet<int>> revertConnections = new(n);
    //     Dictionary<int, HashSet<int>> directConncetions = new(n);
    //     foreach (var connection in connections)
    //     {
    //         if (revertConnections.TryGetValue(connection[1], out var value))
    //         {
    //             value.Add(connection[0]);
    //         }
    //         else
    //             revertConnections[connection[1]] = [connection[0]];
    //
    //         if (directConncetions.TryGetValue(connection[0], out value))
    //         {
    //             value.Add(connection[1]);
    //         }
    //         else
    //             directConncetions[connection[0]] = [connection[1]];
    //     }
    //     int changes = 0;
    //     Dfs(0, [],revertConnections, directConncetions,ref changes);
    //
    //     return changes;
    // }
    //
    // private void Dfs(int node, HashSet<int> visited,Dictionary<int, HashSet<int>> adjacents, Dictionary<int, HashSet<int>> inwards,ref int changes)
    // {
    //     if(!visited.Add(node))
    //         return;
    //     List<int> nodes = [];
    //     if (adjacents.TryGetValue(node, out var adjacent))
    //         nodes.AddRange(adjacent);
    //     if (inwards.TryGetValue(node, out adjacent))
    //     {
    //         adjacent = adjacent.Where(i => !visited.Contains(i)).ToHashSet();
    //         changes += adjacent.Count;
    //         nodes.AddRange(adjacent);
    //     }
    //
    //     foreach (var num in nodes)
    //     {
    //         Dfs(num, visited,adjacents,inwards ,ref changes);
    //     }
    // }

    #endregion
}