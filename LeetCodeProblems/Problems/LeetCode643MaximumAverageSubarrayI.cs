namespace LeetCodeProblems.Problems;

public class LeetCode643MaximumAverageSubarrayI: BaseProblemClass
{
    public double FindMaxAverage(int[] nums, int k) {
        long sum = 0;
        double average = 0;
        double maxAvarge = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        average = (double)sum / k;
        maxAvarge=average;
        int length=nums.Length;
        for (int i = k; i < length; i++)
        {
            sum-=nums[i-k];
            sum += nums[i];
            average= (double)sum / k;
            if(average > maxAvarge)
                maxAvarge=average;
        }
        return maxAvarge;
    }

    public override void Run()
    {
        int[] num = [1, 12, -5, -6, 50, 3];
        int k = 4;
        Console.WriteLine(FindMaxAverage(num, k));
    }
}