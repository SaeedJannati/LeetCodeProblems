namespace LeetCodeProblems.Problems;

public class LeetCode26RemoveDuplicatesFromSortedArray
{
    public int RemoveDuplicates(int[] nums)
    {
        int length = nums.Length;
        int uniquePointer = 0;
        int minValue = nums[0] - 1;
        int nonUniqueCount = 0;
        bool foundNonUnique = false;
        for (int i = 1; i < length; i++)
        {
            if (nums[i] == nums[uniquePointer])
            {
                nonUniqueCount++;
                foundNonUnique = true;
                continue;
            }
            uniquePointer++;
            if(!foundNonUnique)
                continue;
            nums[uniquePointer] = nums[i];
            nums[i] = minValue;
        }

        return length-nonUniqueCount;
    }
}