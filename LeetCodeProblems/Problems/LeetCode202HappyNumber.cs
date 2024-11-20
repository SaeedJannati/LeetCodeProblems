namespace LeetCodeProblems.Problems;

public class LeetCode202HappyNumber: BaseProblemClass
{
    public bool IsHappy(int n)
    {
        HashSet<int> numsSeenSoFar = [n];
        
        while (true)
        {
            n = GetSumSquares(n);
            if (n == 1)
                return true;
            if (!numsSeenSoFar.Add(n))
                return false;
        }
    }

    int GetSumSquares(int n)
    {
        int output = 0;
        int digit = 0;
        while (n>0)
        {
            digit = n % 10;
            output += digit * digit;
            n /= 10;
        }
        return output;
    }

    public override void Run()
    {
        Console.WriteLine(IsHappy(19));
    }
}