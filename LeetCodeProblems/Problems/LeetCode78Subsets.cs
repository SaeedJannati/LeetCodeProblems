using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode78Subsets: BaseProblemClass
{
    public IList<IList<int>> Subsets(int[] nums)
    {
        if (nums == null || nums.Length == 0)
        {
            return [[]];
        }

        if (nums.Length == 1)
            return [[], [nums[0]]];
        int length = nums.Length;
        IList<IList<int>> output = new List<IList<int>>();
        List<Permutation> nextLayer = [];
        for (int i = 0; i < length; i++)
        {
            output.Add([nums[i]]);
            nextLayer.Add(new([nums[i]], i));
        }

        for (int i = 0; i < length; i++)
        {
             AddLayer(nums, nextLayer,length);
            for (int j = 0, e = nextLayer.Count; j < e; j++)
            {
                output.Add([..nextLayer[j].list]);
            }
        }

        output.Add([]);
        return output;
    }

    private void AddLayer(int[] numbers, List<Permutation> previousLayer, int numsLength)
    {
        bool found = false;
        for (int i = previousLayer.Count - 1; i >= 0; i--)
        {
            found = false;
            var temp = new Permutation(previousLayer[i]);
            for (int j = temp.lastIndex+1; j < numsLength; j++)
            {
                if (!found)
                {
                    found = true;
                    previousLayer[i].list.Add(numbers[j]);
                    previousLayer[i].lastIndex = j;
                    continue;
                }

                var newTemp = new Permutation(temp)
                {
                    lastIndex = j
                };
                newTemp.list.Add(numbers[j]);
                previousLayer.Add(newTemp);
            }

            if (!found)
                previousLayer.RemoveAt(i);
        }
    }

    public class Permutation
    {
        public Permutation()
        {
        }

        public Permutation(Permutation permutation)
        {
            list = [..permutation.list];
            lastIndex = permutation.lastIndex;
        }

        public Permutation(IList<int> numbers, int lastIndex)
        {
            list = [..numbers];
            this.lastIndex = lastIndex;
        }

        public int lastIndex;
        public IList<int> list;
    }

    public override void Run()
    {
        int[] nums = [1, 2, 3];
        Console.WriteLine(JsonSerializer.Serialize(Subsets(nums)));
    }
}