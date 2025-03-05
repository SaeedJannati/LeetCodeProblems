namespace LeetCodeProblems.Problems;

public class LeetCode2579CountTotalNumberOfColoredCells
{
    public long ColoredCells(int n)
    {
        long result = 2;
        result *= n;
        result *= n;
        result -= 2 * n;
        result += 1;
        return result;
    }
}