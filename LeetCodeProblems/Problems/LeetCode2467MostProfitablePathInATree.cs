namespace LeetCodeProblems.Problems;

public class LeetCode2467MostProfitablePathInATree: BaseProblemClass
{
    public int MostProfitablePath(int[][] edges, int bob, int[] amount)
    {
        int length = amount.Length;
        int edgesLength = edges.Length;
        var nodes = Enumerable.Range(0, length).Select(i=>new Node()).ToArray();
        Dictionary<int, HashSet<int>> adjacencies = [];
        for (int i = 0; i < edgesLength; i++)
        {
            if (!adjacencies.TryGetValue(edges[i][0], out var adjacent))
                adjacencies.Add(edges[i][0], [edges[i][1]]);
            else
                adjacent.Add(edges[i][1]);
            if (!adjacencies.TryGetValue(edges[i][1], out adjacent))
                adjacencies.Add(edges[i][1], [edges[i][0]]);
            else
                adjacent.Add(edges[i][0]);
        }

        var visited = new bool[length];
        Stack<int> currentLayer = [];
        Stack<int> nextLayer = [];
        int depth = 0;
        currentLayer.Push(0);
        while (currentLayer.Count > 0)
        {
            while (currentLayer.Count > 0)
            {
                int index = currentLayer.Pop();
                visited[index] = true;
                nodes[index].depth = depth;
                foreach (var vert in adjacencies[index])
                {
                    if (visited[vert])
                        continue;
                    if (visited[vert])
                        continue;
                    nextLayer.Push(vert);
                }
            }

            depth++;
            while (nextLayer.Count > 0)
            {
                currentLayer.Push(nextLayer.Pop());
            }
        }
        visited = new bool[length];
        visited[bob] = true;
        DfsFromBob(bob, 0, nodes, adjacencies,visited);
        int maxAmount=int.MinValue;
        visited = new bool[length];
        visited[0] = true;
        DfsFromRoot(0,visited,0,0,nodes,adjacencies,amount,ref maxAmount);
        return maxAmount;
    }

    void DfsFromRoot(int index,bool[]visited, int currentAmount, int turn, Node[] nodes, Dictionary<int, HashSet<int>> adjacencies,
        int[] amounts, ref int maxAmount)
    {
        int amount = amounts[index];
        if (nodes[index].bobVisited)
        {
            if (nodes[index].bobVisitIndex == turn)
                amount /= 2;
            else if (nodes[index].bobVisitIndex < turn)
                amount = 0;
        }

        currentAmount += amount;
        bool isLeaf = true;
        foreach (var vert in adjacencies[index])
        {
            if(visited[vert])
                continue;
            if (nodes[vert].depth < nodes[index].depth)
                continue;
            isLeaf = false;
            visited[vert] = true;
            DfsFromRoot(vert, visited,currentAmount, turn + 1, nodes, adjacencies, amounts, ref maxAmount);
        }

        if (!isLeaf)
            return;
        if (currentAmount > maxAmount)
            maxAmount = currentAmount;
    }

    void DfsFromBob(int index, int turn, Node[] nodes, Dictionary<int, HashSet<int>> adjacencies,bool[]visited)
    {
        nodes[index].bobVisited = true;
        nodes[index].bobVisitIndex = turn;
        foreach (var vert in adjacencies[index])
        {
            if(visited[vert])
                continue;
            if (nodes[vert].depth > nodes[index].depth)
                continue;
            visited[vert] = true;
            DfsFromBob(vert, turn + 1, nodes, adjacencies,visited);
            break;
        }
    }

    public class Node
    {
        public int depth;
        public bool bobVisited;
        public int bobVisitIndex;
    }

    public override void Run()
    {
        int[][] edges = [[0, 1], [1, 2], [1, 3], [3, 4]];
        int bob = 3;
        int[] amount = [-2, 4, 2, -4, 6];
        Console.WriteLine(MostProfitablePath(edges, bob, amount));
    }
}