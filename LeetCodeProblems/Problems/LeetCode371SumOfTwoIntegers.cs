namespace LeetCodeProblems.Problems;

public class LeetCode371SumOfTwoIntegers : BaseProblemClass
{
    public int GetSum(int a, int b)
    {
        var carry = (a&b)<<1;
        return carry==0?a^b:GetSum(carry,a^b);
    }

    public override void Run()
    {
        int a = 7;
        int b = 6;
        Console.WriteLine(GetSum(a, b));
    }
}