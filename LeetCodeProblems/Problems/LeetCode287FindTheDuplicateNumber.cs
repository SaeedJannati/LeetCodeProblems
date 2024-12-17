namespace LeetCodeProblems.Problems;

public class LeetCode287FindTheDuplicateNumber
{
    public int FindDuplicate(int[] nums)
    {
        int length = nums.Length;
        if (length == 2)
            return nums[0];

        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast && fast!=slow);

        slow = nums[0];
        while (slow!=fast && fast!=slow)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
}