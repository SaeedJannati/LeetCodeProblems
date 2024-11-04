namespace LeetCodeProblems.Problems;

public class LeetCode57InsertInterval
{
    public int[][] Insert(int[][] intervals, int[] newInterval)
    {
        List<int[]> output = [];
        int start = 0;
        int end = 0;
        if (intervals.Length == 0)
            return [newInterval];
        if (newInterval[1] < intervals[0][0])
            return [newInterval, ..intervals];
        if (newInterval[0] > intervals[^1][1])
            return [..intervals, newInterval];
        bool dealtWith = false;
        for (int i = 0, e = intervals.Length; i < e; i++)
        {
            if (dealtWith)
            {
                output.Add(intervals[i]);
                continue;
            }

            if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[1])
                return intervals;
            if (intervals[i][1] < newInterval[0])
            {
                output.Add(intervals[i]);
                continue;
            }

            if (intervals[i][0] > newInterval[1])
            {
                output.Add(newInterval);
                output.Add(intervals[i]);
                dealtWith = true;
                continue;
            }

            if (intervals[i][1] >= newInterval[1])
            {
                output.Add([newInterval[0], intervals[i][1]]);
                dealtWith = true;
                continue;
            }

            start = Math.Min(newInterval[0], intervals[i][0]);
            end = newInterval[1];
            for (int j = i + 1; j < e; j++)
            {
                if (intervals[j][0] > newInterval[1])
                    break;
                i = j;
                end = Math.Max(end, intervals[i][1]);
            }

            dealtWith = true;
            output.Add([start, end]);
        }

        return output.ToArray();
    }
}