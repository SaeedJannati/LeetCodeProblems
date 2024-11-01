namespace LeetCodeProblems.Problems;

public class LeetCode172FactorialTrailingZeroes
{
    public int TrailingZeroes(int n)
    {
       var largestPowerOfFive= (int)(Math.Log(n)/Math.Log(5));
       int counter = 0;
       for (int i = 1; i <= largestPowerOfFive; i++)
       {
           counter+=(int)(n/Math.Pow(5, i));
       }
       return counter;
    }
}