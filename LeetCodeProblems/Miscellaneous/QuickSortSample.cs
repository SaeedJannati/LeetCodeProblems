namespace LeetCodeProblems.Miscellaneous;

public class QuickSortSample: BaseProblemClass
{
    public void QuickSort(List<int> nums,int beginIndex, int endIndex)
    {
        if(beginIndex >= endIndex)
            return;
        int pivotIndex = beginIndex;
        for (int i = pivotIndex+1 ; i <= endIndex; i++)
        {
            if (nums[i] >= nums[beginIndex])
            {
                continue;
            }
            pivotIndex++;
            (nums[i], nums[pivotIndex]) = (nums[pivotIndex], nums[i]);
        }
        (nums[beginIndex],nums[pivotIndex])=(nums[pivotIndex], nums[beginIndex]);
        QuickSort(nums,beginIndex, pivotIndex-1);
        QuickSort(nums, pivotIndex+1, endIndex);
    }

    public override void Run()
    {
        List<int> nums = 
            // [4,3,2,1,1,2,3,4];
            // [1,3,2]; 
            [7, 13, 4, 20, 9, 5, 10, 1, 12];
        QuickSort(nums, 0, nums.Count - 1);
        Console.WriteLine(string.Join(",", nums));
    }
}