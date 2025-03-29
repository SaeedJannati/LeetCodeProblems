namespace LeetCodeProblems.Problems;

public class LeetCode2818ApplyOperationsToMaximizeScore : BaseProblemClass
{
    public int MaximumScore(IList<int> nums, int k)
    {
        long kLong = k;
        int length = nums.Count;
        int[] factors = new int[length];
        for (int i = 0; i < length; i++)
        {
            factors[i] = GetFactors(nums[i]);
        }

        Stack<(int factorCount, int index)> monotoniqueStack = [];
        int[] leftWithLargerFactor = new int[length];
        for (int i = 0; i < length; i++)
        {
            while (monotoniqueStack.Count > 0 && monotoniqueStack.Peek().factorCount < factors[i])
            {
                monotoniqueStack.Pop();
            }

            leftWithLargerFactor[i] = monotoniqueStack.Count > 0 ? monotoniqueStack.Peek().index : -1;
            monotoniqueStack.Push((factors[i], i));
        }

        int[] rightWithLargerFactor = new int[length];
        monotoniqueStack.Clear();
        for (int i = length - 1; i >= 0; i--)
        {
            while (monotoniqueStack.Count > 0 && monotoniqueStack.Peek().factorCount <= factors[i])
            {
                monotoniqueStack.Pop();
            }

            rightWithLargerFactor[i] = monotoniqueStack.Count > 0 ? monotoniqueStack.Peek().index : length;
            monotoniqueStack.Push((factors[i], i));
        }

        List<(int number, int index)> sortedNums = nums.Select((num, index) => (num, index)).ToList();
        sortedNums.Sort((i, j) => j.number.CompareTo(i.number));
        long result = 1;
        long delta = 0;
        long contributionTimes = 0;
        foreach (var numInfo in sortedNums)
        {
            delta = rightWithLargerFactor[numInfo.index] - numInfo.index;
            delta *= numInfo.index - leftWithLargerFactor[numInfo.index];
            contributionTimes = Math.Min(delta, kLong);
            kLong -= contributionTimes;
            result = result * ModularExponentiation(numInfo.number, contributionTimes, 1_000_000_007) % 1_000_000_007;
            if (kLong == 0)
                return (int)result;
        }

        return (int)result;
    }

    private int GetFactors(int num)
    {
        if (num == 1)
            return 0;
        HashSet<int> factors = [];
        var factor = 2;
        while (factor * factor <= num)
        {
            while (num % factor == 0)
            {
                factors.Add(factor);
                num /= factor;
            }

            factor++;
        }

        if (num > 1)
            factors.Add(num);
        return factors.Count;
    }

    private long ModularExponentiation(long baseValue, long exp, long mod)
    {
        long result = 1;
        long baseNum = baseValue % mod;

        while (exp > 0)
        {
            if ((exp & 1) == 1)
            {
                result = (result * baseNum) % mod;
            }

            baseNum = (baseNum * baseNum) % mod;
            exp >>= 1;
        }

        return result;
    }

    public override void Run()
    {
        IList<int> nums = [2, 1, 1, 1, 1, 2, 1, 1, 2];
        // [19, 12, 14, 6, 10, 18];
        // [8, 3, 9, 3, 8];
        int k = 9;
        // 3;
        // 2;
        Console.WriteLine(MaximumScore(nums, k));
    }
}