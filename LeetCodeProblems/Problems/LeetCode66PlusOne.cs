namespace LeetCodeProblems.Problems;

public class LeetCode66PlusOne
{
    public int[] PlusOne(int[] digits)
    {
        int remaining = 1;
        
        for (int i = digits.Length - 1; i >= 0; i--)
        {
            digits[i] += remaining;
            remaining = 0;
            if (digits[i] > 9)
            {
                digits[i] -= 10;
                remaining = 1;
            }
        }
        if(remaining == 0)
            return digits;
        return [remaining, ..digits];
    }
}