using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode315CountOfSmallerNumbersAfterSelf: BaseProblemClass
{
    public IList<int> CountSmaller(int[] nums)
    {
        int length = nums.Length;
        List<int> sortedNums=new List<int>(length);
        sortedNums.Add(nums[length - 1]);
        nums[length - 1] = 0;
        for (int i = length - 2; i >= 0; i--)
        {
            int index=BinarySearchInsert(sortedNums, nums[i]);
            nums[i] = index;
        }
        return nums;

    }

    private int BinarySearchInsert(List<int> sortedNums, int num)
    {
        int begin = 0;
        int end= sortedNums.Count - 1;
        int mid = 0;
        while (begin <= end)
        {
            mid=(end+begin)/2;
            if (num>sortedNums[mid])
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }

        }
        sortedNums.Insert(begin, num);
        return begin;
    }


    public override void Run()
    {
        int[] nums =
        [
            26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83, 51, 98, 69, 81, 32, 78, 28, 94, 13, 2,
            97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41
        ];
            // [-1, -1];
            // [-1];
            // [5, 2, 6, 1];
        Console.WriteLine(JsonSerializer.Serialize(CountSmaller(nums)));
    }
}