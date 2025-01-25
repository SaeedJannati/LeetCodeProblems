using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2948MakeLexicographicallySmallestArrayBySwappingElements : BaseProblemClass
{
    public int[] LexicographicallySmallestArray(int[] nums, int limit)
    {
        int length = nums.Length;
        var numClone = (int[])nums.Clone();
        Dictionary<int, HashSet<int>> indices = new(length);
        for (int i = 0; i < length; i++)
        {
            if (!indices.ContainsKey(nums[i]))
            {
                indices[nums[i]] = new();
            }

            indices[nums[i]].Add(i);
        }

        Array.Sort(numClone);
        List<List<int>> groups = [];
        List<PriorityQueue<int, int>> groupsIndices = [];
        int counter = 0;
        while ( counter < length)
        {
            int previous = numClone[counter];
            List<int> group = [numClone[counter]];
            int index = indices[numClone[counter]].First();
            indices[numClone[counter]].Remove(index);
            PriorityQueue<int, int> groupIndices = new();
            groupIndices.Enqueue(index, index);
            counter++;
            while (counter < length && numClone[counter] - previous <= limit)
            {
                group.Add(numClone[counter]);
                index = indices[numClone[counter]].First();
                indices[numClone[counter]].Remove(index);
                groupIndices.Enqueue(index, index);
                previous = numClone[counter];
                counter++;
            }
               
            if(group.Count<2)
                continue;
            groupsIndices.Add(groupIndices);
            groups.Add(group);
        }

        for (int j = 0, e = groups.Count; j < e; j++)
        {
            int groupCount = groups[j].Count;
            for (int i = 0; i < groupCount; i++)
            {
                int index = groupsIndices[j].Dequeue();
                nums[index] = groups[j][i];
            }
        }

        return nums;
    }

    public override void Run()
    {
        int[] nums = [1,60,34,84,62,56,39,76,49,38];
        int limit = 4;
        Console.WriteLine(JsonSerializer.Serialize(LexicographicallySmallestArray(nums, limit)));
    }
}