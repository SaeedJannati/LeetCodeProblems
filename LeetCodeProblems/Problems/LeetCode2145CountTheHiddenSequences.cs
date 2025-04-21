namespace LeetCodeProblems.Problems;

public class LeetCode2145CountTheHiddenSequences
{
    public int NumberOfArrays(int[] differences, int lower, int upper)
    {
        long max = 0;
        long min = 0;
        long sum = 0;
        foreach (var difference in differences)
        {
            sum += difference;
            if (sum > max)
                max = sum;
            if (sum < min)
                min = sum;
        }

        if (max - min > upper - lower)
            return 0;
        int deltaMax =upper-(int)max;
        int deltaMin = lower-(int)min;
        return int.Abs(deltaMax - deltaMin)+1;
        
        
    }
}