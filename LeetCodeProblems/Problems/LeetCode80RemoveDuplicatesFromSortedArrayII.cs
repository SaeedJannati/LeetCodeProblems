namespace LeetCodeProblems.Problems;

public class LeetCode80RemoveDuplicatesFromSortedArrayII
{
    public int RemoveDuplicates(int[] nums)
    {
        int lastNum=nums[0]-1;
        int count = 0;
        int uniquePointer = 0;
        for (int i = 0, e = nums.Length; i < e; i++)
        {
            if (nums[i] != lastNum)
            {
                lastNum = nums[i];
                count = 0;
            }
            else
            {
                count++;
            }

            if (count < 2)
            {
                nums[uniquePointer] = nums[i];
                uniquePointer++;
            }
        }

        return uniquePointer;
    }
}