using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode207CourseSchedule : BaseProblemClass
{
    public bool CanFinish(int numCourses, int[][] prerequisites)
    {
        Dictionary<int, List<int>> adjacents = Enumerable.Range(0, numCourses)
            .ToDictionary(key => key, _ => new List<int>());
        var inDegree = new Dictionary<int, int>(numCourses);
        HashSet<int> verticesWithZeroInDegree = Enumerable.Range(0, numCourses).ToHashSet();
        foreach (var prerequisite in prerequisites)
        {
            adjacents[prerequisite[1]].Add(prerequisite[0]);


            if (inDegree.ContainsKey(prerequisite[0]))
            {
                inDegree[prerequisite[0]]++;
                continue;
            }

            inDegree.Add(prerequisite[0], 1);
            verticesWithZeroInDegree.Remove(prerequisite[0]);
        }

        if (verticesWithZeroInDegree.Count == 0)
            return false;
        Queue<int> zeroInDegree = new Queue<int>();
        int coursesOrderd = 0;
        foreach (var vert in verticesWithZeroInDegree)
        {
            zeroInDegree.Enqueue(vert);
        }

        int current;
        while (zeroInDegree.Count > 0)
        {
            current = zeroInDegree.Dequeue();
            coursesOrderd++;
            foreach (var vert in adjacents[current])
            {
                inDegree[vert]--;
                if (inDegree[vert] == 0)
                    zeroInDegree.Enqueue(vert);
            }
        }

        return coursesOrderd == numCourses;
    }

    public override void Run()
    {
        int[][] prerequisites = [[1, 0]];
        int courseCount = 2;
        Console.WriteLine(JsonSerializer.Serialize(CanFinish(courseCount, prerequisites)));
    }
}