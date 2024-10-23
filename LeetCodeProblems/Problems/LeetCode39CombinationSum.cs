using System.Collections;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode39CombinationSum : BaseProblemClass
{
    public override void Run()
    {
        int[] candidates = [2];
        int target = 1;
        var outPut = CombinationSum(candidates, target);
        Console.WriteLine(JsonSerializer.Serialize(outPut));
    }

    public IList<IList<int>> CombinationSum(int[] candidates, int target)
    {
        if (candidates.Length == 0)
            return [];
        IList<IList<int>> outPut = [];
        List<int> candidatesCorrected = [..candidates];
        for (int i = candidatesCorrected.Count - 1; i >= 0; i--)
        {
            if (candidatesCorrected[i] <= target)
            {
                break;
            }
            if (candidatesCorrected[i] > target)
                candidatesCorrected.Remove(candidatesCorrected[i]);
        }

        if (candidatesCorrected.Count == 0)
            return [];
        candidatesCorrected.Sort();
        if (target < candidatesCorrected[0])
            return [];
        candidatesCorrected.ForEach(i => outPut.Add([i]));

        var shouldContinue = true;
        while (shouldContinue)
        {
            shouldContinue = AddLayer(candidatesCorrected, target, outPut);
        }

        for (int i = outPut.Count - 1; i >= 0; i--)
        {
            if (outPut[i].Sum() != target)
                outPut.RemoveAt(i);
        }

        return outPut;
    }

    private bool AddLayer(List<int> candidates, int target, IList<IList<int>> outPut)
    {
        int sum;
        bool hasAddedAny = false;
        for (int i = outPut.Count - 1; i >= 0; i--)
        {
            sum = outPut[i].Sum();
            if (sum == target)
                continue;
            if (sum + candidates[0] > target)
            {
                outPut.Remove(outPut[i]);
                continue;
            }

            bool addedToOrig = false;
            IList<int> temp = [..outPut[i]];
            foreach (var num in candidates)
            {
                if (sum + num > target)
                    break;
                if (num < outPut[i][^1])
                    continue;
                hasAddedAny = true;
                if (!addedToOrig)
                {
                    outPut[i].Add(num);
                    addedToOrig = true;
                    continue;
                }

                outPut.Add([..temp, num]);
            }
        }

        return hasAddedAny;
    }
}