namespace LeetCodeProblems.Problems;

public class LeetCode1137NthTribonacciNumber
{
    public int Tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n < 3)
            return 1;
        int thirdBefore = 0;
        int secondBefore = 1;
        int firstBefore = 1;
        int current = 2;
        for (int i = 3; i <= n; i++)
        {
            current = thirdBefore+secondBefore+firstBefore;
            thirdBefore = secondBefore;
            secondBefore = firstBefore;
            firstBefore = current;
        }

        return current;
    }
}