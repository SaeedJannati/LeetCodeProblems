using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2127MaximumEmployeesToBeInvitedToAMeeting : BaseProblemClass
{
    public int MaximumInvitations(int[] favorite)
    {
        int length = favorite.Length;
        int result = 0;
        List<HashSet<int>> cycles = [];
        List<List<int>> chains = [];
        var visited = Enumerable.Repeat(0, length).ToList();
        HashSet<int> allNodesInCycle = [];
        for (int i = 0; i < length; i++)
        {
            List<int> currentPath = [];
            int cycleHead = 0;
            if (CycleDetectionDfs(favorite, visited, currentPath, i, ref cycleHead))
                continue;
            cycleHead = currentPath.IndexOf(cycleHead);
            cycles.Add([..currentPath.Where((_, ind) => ind >= cycleHead)]);
            foreach (int node in cycles[^1])
            {
                allNodesInCycle.Add(node);
            }
        }

        List<List<int>> visitedNodes = [];
        for (int i = 0; i < length; i++)
            visitedNodes.Add([0, 0]);
        foreach (int node in allNodesInCycle)
        {
            visitedNodes[node][0] = -1;
        }

        Dictionary<int, int> chainsInfo = [];
        for (int i = 0; i < length; i++)
        {
            if (visitedNodes[i][0] == -1)
                continue;
            Stack<int> nodesInChain = [];
            int currentTailIndex = -1;
            int tail = -1;
            int numToAdd = 0;
            ChainDetectionDfs(favorite, visitedNodes, i, nodesInChain, ref currentTailIndex);
            
            if (nodesInChain.Count == 0)
                continue;
            if (currentTailIndex != -1)
            {
                numToAdd = visitedNodes[currentTailIndex][0];
                tail = visitedNodes[currentTailIndex][1];
            }

            if (tail == -1)
                tail = nodesInChain.Peek();
            int counter = visitedNodes[nodesInChain.Peek()][0] == -1 ? 0 : 1;
            int node = 0;
            int distance = 0;
            while (nodesInChain.Count > 0)
            {
                node = nodesInChain.Pop();
                distance = counter + numToAdd;
                visitedNodes[node][0] += distance;
                visitedNodes[node][1] = tail;
                counter++;
            }

            if (visitedNodes[node][0] > 0)
            {
                if (!chainsInfo.ContainsKey(tail))
                {
                    chainsInfo[tail] = visitedNodes[node][0];
                    continue;
                }

                if (visitedNodes[node][0] > chainsInfo[tail])
                    chainsInfo[tail] = visitedNodes[node][0];
            }
        }

        int maxLengthChain = 0;
        if (chains.Count > 0)
            maxLengthChain = chains.Max(chain => chain.Count);
        if (maxLengthChain == length)
            return length;
        result = 0;
        if (cycles.Count > 0)
            result = cycles.Max(cycle => cycle.Count);
        var twoLengthCycles = cycles.Where(c => c.Count == 2).ToList();

        int count = 0;
        foreach (var cycle in twoLengthCycles)
        {
            if (chainsInfo.ContainsKey(cycle.First()))
            {
                count += chainsInfo[cycle.First()];
            }

            if (chainsInfo.ContainsKey(cycle.Last()))
            {
                count += chainsInfo[cycle.Last()];
            }

            count += 2;
            if (count > result)
                result = count;
        }

        return result;
    }

    private void ChainDetectionDfs(int[] favorite, List<List<int>> visitedNodes, int i, Stack<int> nodesInChain,
        ref int tailIndex)
    {
        if (visitedNodes[i][0] == -1)
        {
            nodesInChain.Push(i);
            return;
        }

        if (visitedNodes[i][0] > 0)
        {
            tailIndex = i;
            return;
        }

        nodesInChain.Push(i);
        ChainDetectionDfs(favorite, visitedNodes, favorite[i], nodesInChain, ref tailIndex);
    }

    private bool CycleDetectionDfs(int[] favorite, List<int> visited, List<int> currentPath, int item,
        ref int cycleHead)
    {
        switch (visited[item])
        {
            case 2:
                return true;
            case 1:
                visited[item] = 2;
                cycleHead = item;
                return false;
        }

        visited[item] = 1;
        currentPath.Add(item);
        if (!CycleDetectionDfs(favorite, visited, currentPath, favorite[item], ref cycleHead))
        {
            visited[item] = 2;
            return false;
        }

        visited[item] = 2;
        return true;
    }

    public override void Run()
    {
        int[] favorite =
            // [1, 0, 3, 2, 5, 6, 7, 4, 9, 8, 11, 10, 11, 12, 10];
            [1, 0, 0, 2, 1, 4, 7, 8, 9, 6, 7, 10, 8];
        // [2, 2, 1, 2];
        // [1, 2, 0];
        // [1, 0];
        // [2, 3, 1, 4, 1, 6, 7, 4];
        // [2,3,6,4,1,2,7,0];
        Console.WriteLine(MaximumInvitations(favorite));
    }
}