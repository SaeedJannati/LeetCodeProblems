using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode210CourseScheduleII: BaseProblemClass
{
    public override void Run()
    {
        int[][] prerequisites = [[1, 0]];
        int courseCount = 2;
        Console.WriteLine(JsonSerializer.Serialize(FindOrder(courseCount, prerequisites)));
    }
    public int[] FindOrder(int numCourses, int[][] prerequisites)
    {
        Dictionary<int, List<int>> adjacents =
            Enumerable.Range(0, numCourses).ToDictionary(k => k, v => new List<int>());
        Dictionary<int, int> inDegrees = new(numCourses);
        HashSet<int> zeroInDegrees = Enumerable.Range(0, numCourses).ToHashSet();
        foreach (var prerequisite in prerequisites)
        {
            adjacents[prerequisite[1]].Add(prerequisite[0]);
            if (inDegrees.ContainsKey(prerequisite[0]))
            {
                inDegrees[prerequisite[0]]++;
                continue;
            }

            zeroInDegrees.Remove(prerequisite[0]);
            inDegrees[prerequisite[0]] = 1;
        }

        if (zeroInDegrees.Count == 0)
            return [];
        List<int> result = new(numCourses);
        Queue<int> queue = new(numCourses);
        foreach (var zeroInDegree in zeroInDegrees)
        {
            queue.Enqueue(zeroInDegree);
        }

        int current = 0;
        while (queue.Count > 0)
        {
            current = queue.Dequeue();
            result.Add(current);
            foreach (var vert in adjacents[current])
            {
                inDegrees[vert]--;
                if(inDegrees[vert] == 0)
                    queue.Enqueue(vert);
            }
        }

        if (result.Count != numCourses)
            return [];
        return result.ToArray();
    }
}