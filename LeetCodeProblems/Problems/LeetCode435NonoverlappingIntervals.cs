namespace LeetCodeProblems.Problems;

public class LeetCode435NonoverlappingIntervals
{
    public int EraseOverlapIntervals(int[][] intervals)
    {
        Array.Sort(intervals, (x, y) =>
        {
            int compareSecond = x[1].CompareTo(y[1]);
            return compareSecond != 0 ? compareSecond : x[0].CompareTo(y[0]);
        });
        int currentStart = intervals[0][0];
        int currentEnd = intervals[0][1];
        int removedCount = 0;
        for (int i = 1, e = intervals.Length; i < e; i++)
        {
            if (intervals[i][0] > currentStart && intervals[i][0] < currentEnd)
            {
                removedCount++;
                continue;
            }
            if (intervals[i][0] == currentStart && intervals[i][1] == currentEnd)
            {
                removedCount++;
                continue;
            }
            currentEnd = intervals[i][1];
        }

        return removedCount;
    }
}