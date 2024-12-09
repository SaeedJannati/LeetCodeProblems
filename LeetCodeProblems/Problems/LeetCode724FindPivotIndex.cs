namespace LeetCodeProblems.Problems;

public class LeetCode724FindPivotIndex
{
    public int PivotIndex(int[] nums)
    {
        int length = nums.Length;
        long[] pivot = new long[length];
        long sum = 0;
        for (int i = 0; i < length; i++)
        {
            pivot[i] = sum;
            sum += nums[i];
        }

        sum = 0;
        int index = int.MaxValue;
        for (int i = length - 1; i >= 0; i--)
        {
            pivot[i] -= sum;
            sum += nums[i];
            if(pivot[i] == 0)
                index = i;
        }

        if (index == int.MaxValue)
            return -1;
        return index;
    }
}