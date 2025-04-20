namespace LeetCodeProblems.Problems;

public class LeetCode2179CountGoodTripletsInAnArray : BaseProblemClass
{
    public long GoodTriplets(int[] nums1, int[] nums2)
    {
        int n = nums1.Length;
        int[] indexInNums2 = new int[n];
        for (int i = 0; i < n; i++)
        {
            indexInNums2[nums2[i]] = i;
        }

        int[] transformed = new int[n];
        for (int i = 0; i < n; i++)
        {
            transformed[i] = indexInNums2[nums1[i]];
        }
        var leftTree = new FenwickTree(n);
        var rightTree = new FenwickTree(n);
        foreach (int x in transformed)
        {
            rightTree.Update(x, 1);
        }

        long result = 0;

        for (int j = 0; j < n; j++)
        {
            int idx = transformed[j];
            rightTree.Update(idx, -1);
            long leftCount = leftTree.Query(idx - 1);
            long rightCount = rightTree.Query(n - 1) - rightTree.Query(idx);
            result += leftCount * rightCount;
            leftTree.Update(idx, 1);
        }

        return result;
    }

    private class FenwickTree(int size)
    {
        private readonly long[] _tree = new long[size + 1];

        public void Update(int index, long value)
        {
            index++;
            while (index <= size)
            {
                _tree[index] += value;
                index += index & -index;
            }
        }

        public long Query(int index)
        {
            index++;
            long sum = 0;
            while (index > 0)
            {
                sum += _tree[index];
                index -= index & -index;
            }

            return sum;
        }
    }

    public override void Run()
    {
        int[] nums1 = [2, 0, 1, 3];
        int[] nums2 = [0, 1, 2, 3];
        Console.WriteLine(GoodTriplets(nums1, nums2));
    }
}