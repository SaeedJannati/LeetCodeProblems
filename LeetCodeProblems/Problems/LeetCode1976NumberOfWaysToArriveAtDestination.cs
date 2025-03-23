using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode1976NumberOfWaysToArriveAtDestination : BaseProblemClass
{
    public int CountPaths(int n, int[][] roads)
    {
        var distances = Enumerable.Repeat(long.MaxValue, n).ToArray();
        distances[0] = 0;
        var visited = new bool[n];
        Dictionary<int, List<(int node,int distance)>> adjPlus = [];
        for (int i = 0; i < n; i++)
            adjPlus[i] = [];
        foreach (var edge in roads)
        {
            adjPlus[edge[0]].Add((edge[1], edge[2]));
            adjPlus[edge[1]].Add((edge[0], edge[2]));
        }

        var queue = new PriorityQueue<(long distance, int node), long>();
        queue.Enqueue((0, 0), 0);
        long newDistance = 0;
        while (queue.Count > 0)
        {
            var nodeInfo = queue.Dequeue();
            if(nodeInfo.distance >distances[nodeInfo.node])
                continue;
            foreach (var edgeInfo in adjPlus[nodeInfo.node])
            {
                newDistance = distances[nodeInfo.node] + edgeInfo.distance;
                if(newDistance >= distances[edgeInfo.node])
                    continue;
                distances[edgeInfo.node] = newDistance;
                queue.Enqueue((newDistance, edgeInfo.node), newDistance);
            }
        }

        Dictionary<int, HashSet<int>> adjMinus = [];
        foreach (var edge in roads)
        {
            if (distances[edge[0]] + edge[2] == distances[edge[1]])
            {
                if(!adjMinus.ContainsKey(edge[1]))
                    adjMinus[edge[1]] = [];
                adjMinus[edge[1]].Add(edge[0]);
            }

            if (distances[edge[1]] + edge[2] == distances[edge[0]])
            {
                if(!adjMinus.ContainsKey(edge[0]))
                    adjMinus[edge[0]] = [];
                adjMinus[edge[0]].Add(edge[1]);
            }
        }

        Dictionary<int, int> memoisation = [];
        memoisation[0] = 1;
        return CalculateWayCounts(adjMinus, memoisation, n - 1);
    }

    int CalculateWayCounts(Dictionary<int, HashSet<int>> adjMinus, Dictionary<int,int> memoisation,int node)
    {
        if(memoisation.ContainsKey(node))
            return memoisation[node];
        long result = 0;
        if(!adjMinus.ContainsKey(node))
            return 0;
        foreach (var vert in adjMinus[node])
        {
            result += CalculateWayCounts(adjMinus,memoisation, vert);
            result %= 1_000_000_007;
        }
        memoisation[node]= (int)(result% 1_000_000_007);
        return memoisation[node];
    }
    public override void Run()
    {
        int n = 7;
        int[][] roads =
        [
            [0, 6, 7], [0, 1, 2], [1, 2, 3], [1, 3, 3], [6, 3, 3], [3, 5, 1], [6, 5, 1], [2, 5, 1], [0, 4, 5], [4, 6, 2]
        ];
        Console.WriteLine(CountPaths(n, roads));
    }
}