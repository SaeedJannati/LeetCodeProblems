using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2523ClosestPrimeNumbersInRange : BaseProblemClass
{
    public int[] ClosestPrimes(int left, int right)
    {
        if (left == right)
            return [-1, -1];
        var maxIteration = (int)Math.Sqrt(right) + 1;
        var nums = Enumerable.Range(2, right - 1).ToHashSet();
        int minPrime = 2;
        int primeIndex = 0;
        while (minPrime <= maxIteration)
        {
            var coefficient = minPrime;
            var numToRemove = minPrime * coefficient;
            while (true)
            {
                numToRemove = minPrime * coefficient;
                if (numToRemove > right)
                    break;
                coefficient++;
                if (nums.Contains(numToRemove))
                    nums.Remove(numToRemove);
            }

            primeIndex++;
            minPrime = nums.First(i=>i>minPrime);
        }

        int[] closestPrimes = [-1, -1];
        int minDelta = int.MaxValue;
        int delta = 0;
        var noms = nums.ToList();
        for (int i = 0, e = nums.Count - 1; i < e; i++)
        {
            if (noms[i] <left)
                continue;
            delta = noms[i + 1] - noms[i];
            if (delta < minDelta)
            {
                minDelta = delta;
                closestPrimes = [noms[i], noms[i + 1]];
            }
        }

        return closestPrimes;
    }

    public override void Run()
    {
        int left = 10;
        int right = 19;
        Console.WriteLine(JsonSerializer.Serialize(ClosestPrimes(left, right)));
    }
}