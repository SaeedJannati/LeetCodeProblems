namespace LeetCodeProblems.Problems;

public class LeetCode312BurstBalloons: BaseProblemClass
{
    public int MaxCoins(int[] nums)
    {
        int length = nums.Length;
        List<int> numsList = new(length + 2);
        numsList.Add(1);
        numsList.AddRange(nums);
        numsList.Add(1);
        int[,] dp = new int[length + 2, length + 2];
        for (int i = 1; i <= length; i++)
        {
            for (int j = 0; j <= length - i; j++)
            {
                int end = i + j + 1;
                int delta = numsList[j] * numsList[end];
                int maxValue = 0;
                for (int k = j+1; k < end; k++)
                {
                    int current = dp[j, k] + dp[k, end] + delta * numsList[k];
                    if (current > maxValue)
                        maxValue = current;
                }

                dp[j, end] = maxValue;
            }
        }

        return dp[0, length+1];
    }

    public override void Run()
    {
        int[] nums = [3, 1, 5, 8];
        Console.WriteLine(MaxCoins(nums));
    }
}