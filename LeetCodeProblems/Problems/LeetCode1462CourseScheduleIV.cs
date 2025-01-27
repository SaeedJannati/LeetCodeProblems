using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode1462CourseScheduleIV : BaseProblemClass
{
    public IList<bool> CheckIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries)
    {
        var isReachable = new bool[numCourses, numCourses];
        foreach (var edge in prerequisites)
        {
            isReachable[edge[0], edge[1]] = true;
        }

        for (var k = 0; k< numCourses;k++)
        for (var i =0; i < numCourses; i++)
        for (var j= 0; j < numCourses; j++)
        {
            if(isReachable[i,j])
                continue;
            if(isReachable[i , k]&&isReachable[k , j])
                isReachable[i , j] = true;
        }

        List<bool> result = new(queries.Length);
        foreach (var query in queries)
        {
            result.Add(isReachable[query[0], query[1]]);
        }

        return result;
    }

    public override void Run()
    {
        int numCourses = 3;
        int[][] prerequisites = [[1, 0], [2, 0]];
        int[][] queries = [[0, 1], [2, 0]];
        Console.WriteLine(JsonSerializer.Serialize(CheckIfPrerequisite(numCourses, prerequisites, queries)));
    }
}