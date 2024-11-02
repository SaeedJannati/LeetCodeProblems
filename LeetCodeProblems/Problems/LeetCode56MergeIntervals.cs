namespace LeetCodeProblems.Problems;

public class LeetCode56MergeIntervals
{
    public int[][] Merge(int[][] intervals)
    {
        SortedDictionary<int, int> intervalsDict = [];
        foreach (var interval in intervals)
        {
            if(intervalsDict.ContainsKey(interval[0]))
                if(intervalsDict[interval[0]] > interval[1])
                    continue;
            intervalsDict[interval[0]] = interval[1];
        }

        List<int[]> result = [];
        bool beginFound = false;
        bool endFound = false;
        int currentBegining = 0;
        int currentEnd = 0;
        foreach (var pair in intervalsDict)
        {
            if (!beginFound)
            {
                currentBegining = pair.Key;
                currentEnd = pair.Value;
                beginFound = true;
                continue;
            }

            if (pair.Key > currentEnd)
            {
                result.Add([currentBegining, currentEnd]);
                currentBegining = pair.Key;
                currentEnd = pair.Value;
                continue;
            }

            if (pair.Value > currentEnd)
                currentEnd = pair.Value;
        }

        result.Add([currentBegining, currentEnd]);
        return result.ToArray();
    }
}