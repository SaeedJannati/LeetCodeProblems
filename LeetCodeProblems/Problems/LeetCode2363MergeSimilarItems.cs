using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2363MergeSimilarItems: BaseProblemClass
{
    public IList<IList<int>> MergeSimilarItems(int[][] items1, int[][] items2) {
        SortedDictionary<int,int> dict = new SortedDictionary<int,int>();
        for (int i = 0,e=items1.Length; i <e; i++)
        {
                if(!dict.TryAdd(items1[i][0],items1[i][1]))
                    dict[items1[i][0]] += items1[i][1];
            
        }
        for (int i = 0,e=items2.Length; i <e; i++)
        {
            if(!dict.TryAdd(items2[i][0],items2[i][1]))
                dict[items2[i][0]] += items2[i][1];
        }
        IList<IList<int>> result = new List<IList<int>>(dict.Count);
        foreach (var pair   in dict)
        {
            result.Add([pair.Key,pair.Value]);
        }

        return result;
    }


    public override void Run()
    {
        int[][] items1 = [[1, 1], [4, 5], [3, 8]];
        int[][] items2 = [[3,1],[1,5]];
        Console.WriteLine(JsonSerializer.Serialize(MergeSimilarItems(items1,items2)));
    }
}