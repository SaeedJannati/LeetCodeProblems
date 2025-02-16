using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode1718ConstructTheLexicographicallyLargestValidSequence : BaseProblemClass
{
    public int[] ConstructDistancedSequence(int n)
    {
        if (n == 1)
            return [1];
        int length = 2 * n - 1;
        bool[] visited = new bool[n + 1];
        int[] result = new int[length];
        visited[n] = true;
        result[0] = n;
        result[n] = n;
        BackTrack(result, visited, n, n, 1, 0, length);
        return result;
    }

    bool BackTrack(int[] result, bool[] visited, int n, int number, int index, int visitedNumber, int length)
    {
        if (visitedNumber == n)
            return true;
        visited[number] = true;
        visitedNumber++;
        Stack<int> changedIndices = new(2);
        for (int i = n - 1; i >= 1; i--)
        {
            if (visited[i])
                continue;
            if (i > 1)
            {
                if (index + i >= length)
                    continue;
                if (result[index + i] != 0)
                    continue;
            }

            result[index] = i;
            changedIndices.Push(index);
            if (i > 1)
            {
                result[index + i] = i;
                changedIndices.Push(index + i);
            }

            if (visitedNumber == n - 1)
                return true;
            for (int j = index + 1; j < length; j++)
            {
                if (result[j] != 0)
                    continue;
                if (BackTrack(result, visited, n, i, j, visitedNumber, length))
                    return true;
            }

            while (changedIndices.Count > 0)
            {
                result[changedIndices.Pop()] = 0;
            }
        }

        visited[number] = false;

        return false;
    }

    public override void Run()
    {
        int n =
            4;
            // 1;
            // 2;
        // 5;
        // 3;
        Console.WriteLine(JsonSerializer.Serialize(ConstructDistancedSequence(n)));
    }
}