namespace LeetCodeProblems.Problems;

public class LeetCode191NumberOf1Bits
{
    public int HammingWeight(int n)
    {
        var output = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
                output++;
            n /= 2;
        }

        return output;
    }
}