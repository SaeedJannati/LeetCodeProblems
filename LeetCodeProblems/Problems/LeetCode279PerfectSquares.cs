namespace LeetCodeProblems.Problems;

public class LeetCode279PerfectSquares : BaseProblemClass
{
    public int NumSquares(int n)
    {
        int maxNum = (int) Math.Sqrt(n);
        int[] squares = Enumerable.Range(1, maxNum).Select(i => i * i).ToArray();
        int[] minNums = new int[n+1];
        for (int i = 1, e = n + 1; i < e; i++)
        {
            minNums[i] = i;
        }

        
        for (int i = 1; i < maxNum; i++)
        {
            for (int j = 1,e=n+1; j < e; j++)
            {
                if (squares[i] > j)
                {
                    continue;
                }
                if(minNums[ j - squares[i]] + 1<minNums[j])
                    minNums[j] = minNums[ j - squares[i]] + 1;
            }
        }

        return minNums[^1];
    }

    public override void Run()
    {
        int n = 12;
        Console.WriteLine(NumSquares(n));
    }
}