using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode216CombinationSumIII : BaseProblemClass
{
    public IList<IList<int>> CombinationSum3(int k, int n)
    {
        List<Sum> result = [];
        for (int i = 1; i < 10; i++)
        {
            result.Add(new([i],i));
        }

        for (int i = 1; i < k; i++)
        {
            AddLayer(n,result);
        }
        IList<IList<int>> combinations = result
            .Where(i=>i.sum==n)
            .Select(i=>i.nums)
            .ToList();
        return combinations;
    }

    void AddLayer(int n, List<Sum> output)
    {
        bool found = false;
        int sum;
        for (int i = output.Count - 1; i >= 0; i--)
        {
            IList<int> temp = [..output[i].nums];
            sum = output[i].sum;
            found = false;
            for (int j = output[i].nums[^1] + 1; j < 10; j++)
            {
                if (sum + j > n)
                    continue;

                if (!found)
                {
                    found = true;
                    output[i].nums.Add(j);
                    output[i].sum += j;
                    continue;
                }

                var newSum = new Sum(temp, sum + j);
                newSum.nums.Add(j);
                output.Add(newSum);
            }
            if(!found)
                output.RemoveAt(i);
        }
    }

    class Sum
    {
        public Sum(IList<int> nums, int sum)
        {
            this.nums = [..nums];
            this.sum = sum;
        }

        public IList<int> nums;
        public int sum;
    }

    public override void Run()
    {
        int n = 7;
        int k = 3;
        Console.WriteLine(JsonSerializer.Serialize(CombinationSum3(k,n)));
    }
}