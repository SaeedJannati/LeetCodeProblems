namespace LeetCodeProblems.Problems;

public class LeetCode1514PathWithMaximumProbability
{
    public double MaxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node)
    {
        Dictionary<int, Dictionary<int, double>> adjPlus = [];
        bool[] visited = new bool[n];
        for (int i = 0, e = succProb.Length; i < e; i++)
        {
            if (!adjPlus.ContainsKey(edges[i][0]))
                adjPlus[edges[i][0]] = [];
            adjPlus[edges[i][0]][edges[i][1]] = succProb[i];

            if (!adjPlus.ContainsKey(edges[i][1]))
                adjPlus[edges[i][1]] = [];
            adjPlus[edges[i][1]][edges[i][0]] = succProb[i];
        }

        var probabilities = Enumerable.Repeat(-2d, n).ToArray();
        probabilities[start_node] = 1;
        Dictionary<int, HashSet<double>> changedWeights = [];
        var queue = new PriorityQueue<int, double>();
        queue.Enqueue(start_node, 0);
        int visitedCount= 0;
        visited[start_node] = true;
        while (visitedCount <n)
        {
            queue.TryDequeue(out var node, out var weight);
            if (changedWeights.ContainsKey(node))
            {
                if (changedWeights[node].Contains(weight))
                {
                    changedWeights[node].Remove(weight);
                    if (changedWeights[node].Count == 0)
                        changedWeights.Remove(node);
                    continue;
                }
            }
            visited[node] = true;
            visitedCount++;
            if (!adjPlus.ContainsKey(node))
                continue;
            foreach (var vert in adjPlus[node])
            {
                if (visited[vert.Key])
                    continue;
                var probability = probabilities[node] * vert.Value;
                var beforeProbality = probabilities[vert.Key];
                if (probabilities[vert.Key] < probability)
                {
                    probabilities[vert.Key] = probability;
                }

                if (!changedWeights.ContainsKey(vert.Key))
                    changedWeights[vert.Key] = [];
                changedWeights[vert.Key].Add(beforeProbality);
                queue.Enqueue(vert.Key,-probability);
            }
        }
        return probabilities[end_node]>0? probabilities[end_node] : 0;
    }
}