using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode46Permutations : BaseProblemClass
{
    public override void Run()
    {
        int[] input = [1, 2, 3];
        var outPut = Permute(input);
        Console.WriteLine(JsonSerializer.Serialize(outPut));
    }

    public IList<IList<int>> Permute(int[] nums)
    {
        IList<IList<int>> outPut = [];
        if (nums.Length == 0)
            return outPut;
        for (int i = 0; i < nums.Length; i++)
        {
            AddPermutationLayer(nums,outPut);
        }
        return outPut;
    }

    private void AddPermutationLayer(int[] nums, IList<IList<int>> outPut)
    {
        if (outPut.Count == 0)
        {
            foreach (var num in nums)
            {
                outPut.Add([num]);
            }
            return;
        }

        bool addedToCurrent = false;
        for(int i=outPut.Count-1; i>=0; i--)
        {
            addedToCurrent = false;
            IList<int> temp = [..outPut[i]];
            foreach (var num in nums)
            {
               if(outPut[i].Contains(num))
                   continue;
               if (!addedToCurrent)
               {
                   outPut[i].Add(num);
                   addedToCurrent = true;
                   continue;
               }
               outPut.Add([..temp,num]);
            }
        }
    }
}