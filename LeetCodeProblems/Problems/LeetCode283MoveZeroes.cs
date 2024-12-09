namespace LeetCodeProblems.Problems;

public class LeetCode283MoveZeroes
{
    public void MoveZeroes(int[] nums)
    {
        int firstPointer = 0;
        int length = nums.Length;
        int temp = 0;
        for (int i = 0; i < length; i++)
        {
            if(nums[i] == 0)
                continue;
            temp = nums[i];
            nums[i] = 0;
            nums[firstPointer] = temp;
            firstPointer++;
        }
    }
}