namespace LeetCodeProblems.Problems;

public class LeetCode2493DivideNodesIntoTheMaximumNumberOfGroups : BaseProblemClass
{
    public int MagnificentSets(int n, int[][] edges)
    {
        bool[] visited = new bool [n + 1];
        bool[] colours = new bool[n + 1];
        int levels = 0;
        Queue<int> currentLayer = [];
        HashSet<int> nextLayerSet = [];
        var edgeList = new List<HashSet<int>>();
        for (int i = 0; i < n + 1; i++)
            edgeList.Add(new HashSet<int>());
        foreach (var t in edges)
        {
            edgeList[t[0]].Add(t[1]);
            edgeList[t[1]].Add(t[0]);
        }

        List<List<int>> groups = new List<List<int>>();
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            List<int> group = [i];
            currentLayer.Enqueue(i);
            visited[i] = true;
            int node = 0;
            while (currentLayer.Count > 0)
            {
                levels++;
                while (currentLayer.Count > 0)
                {
                    node = currentLayer.Dequeue();
                    foreach (var vert in edgeList[node])
                    {
                        if (visited[vert])
                        {
                            continue;
                        }

                        visited[vert] = true;
                        nextLayerSet.Add(vert);
                    }
                }

                foreach (var num in nextLayerSet)
                {
                    group.Add(num);
                    currentLayer.Enqueue(num);
                }

                nextLayerSet = [];
            }

            groups.Add(group);
        }

        int totalLevels = 0;
        int maxLevelInGroup = 0;
        foreach (var group in groups)
        {
            maxLevelInGroup = 0;
            foreach (int i in group)
            {
                levels = 0;
                visited = new bool[n + 1];
                colours = new bool[n + 1];
                var colour = false;
                currentLayer.Enqueue(i);
                visited[i] = true;
                int node = 0;
                while (currentLayer.Count > 0)
                {
                    levels++;
                    while (currentLayer.Count > 0)
                    {
                        node = currentLayer.Dequeue();
                        foreach (var vert in edgeList[node])
                        {
                            if (visited[vert])
                            {
                                if (colours[vert] == colour)
                                    return -1;
                                continue;
                            }

                            visited[vert] = true;
                            colours[vert] = !colour;
                            nextLayerSet.Add(vert);
                        }
                    }

                    colour = !colour;
                    foreach (var num in nextLayerSet)
                    {
                        currentLayer.Enqueue(num);
                    }

                    nextLayerSet = [];
                }
                if(levels>maxLevelInGroup)
                    maxLevelInGroup = levels;
            }
            totalLevels += maxLevelInGroup;
        }
        return totalLevels;
    }

    public override void Run()
    {
        int n = 26;
        int[][] edges =
        [
            [9, 16], [8, 3], [20, 21], [12, 16], [14, 3], [7, 21], [22, 3], [22, 18], [11, 16], [25, 4], [2, 4],
            [14, 21], [23, 3], [17, 3], [2, 16], [24, 16], [13, 4], [10, 21], [7, 4], [9, 18], [14, 18], [14, 4],
            [14, 16], [1, 3], [25, 18], [17, 4], [1, 16], [23, 4], [2, 21], [5, 16], [24, 18], [20, 18], [19, 16],
            [24, 21], [9, 3], [24, 3], [19, 18], [25, 16], [19, 21], [6, 3], [26, 18], [5, 21], [20, 16], [2, 3],
            [10, 18], [26, 16], [8, 4], [11, 21], [23, 16], [13, 16], [25, 3], [7, 18], [19, 3], [20, 4], [26, 3],
            [23, 18], [15, 18], [17, 18], [10, 16], [26, 21], [23, 21], [7, 16], [8, 18], [10, 4], [24, 4], [7, 3],
            [11, 18], [9, 4], [26, 4], [13, 21], [22, 16], [22, 21], [20, 3], [6, 18], [9, 21], [10, 3], [22, 4],
            [1, 18], [25, 21], [11, 4], [1, 21], [15, 3], [1, 4], [15, 16], [2, 18], [13, 3], [8, 21], [13, 18],
            [11, 3], [15, 21], [8, 16], [17, 16], [15, 4], [12, 3], [6, 4], [17, 21], [5, 18], [6, 16], [6, 21],
            [12, 4], [19, 4], [5, 3], [12, 21], [5, 4]
        ];
        // [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]];
        Console.WriteLine(MagnificentSets(n, edges));
    }
}