namespace LeetCodeProblems.Problems;

public class LeetCode1014BestSightseeingPair
{
    public int MaxScoreSightseeingPair(int[] values)
    {
        int max = int.MinValue;
        int current = 0;
        int[] startPoint = [..values];
        int maxStartPoint = int.MinValue;
        for (int i = 0; i < values.Length; i++)
        {
            startPoint[i] += i;
        }

        maxStartPoint = startPoint[0];

        for (int i = 1; i < values.Length ; i++)
        {
            current = values[i] - i+maxStartPoint;
            if(current > max)
                max = current;
            if(startPoint[i]>maxStartPoint)
                maxStartPoint = startPoint[i];
        }
        return max;
    }
}