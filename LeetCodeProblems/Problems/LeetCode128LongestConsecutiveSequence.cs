namespace LeetCodeProblems.Problems;

public class LeetCode128LongestConsecutiveSequence
{
    public int LongestConsecutive(int[] nums)
    {
        if (nums.Length == 0)
            return 0;
        if (nums.Length == 1)
            return 1;
        var numsIsSet = nums.ToHashSet();
        int currentSteark = 0;
        int maxSteark = 1;
        bool hasNext = false; 
        foreach (var num in numsIsSet)
        {
            currentSteark = 0;
            if(numsIsSet.Contains(num-1))
                continue;
            currentSteark++;
            while (numsIsSet.Contains(num+currentSteark))
            {
                currentSteark++;
                maxSteark = Math.Max(maxSteark, currentSteark);
            }
        }

        return maxSteark;
    }
}