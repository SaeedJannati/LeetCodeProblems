namespace LeetCodeProblems.Problems;

public class LeetCodefeat_AddLeetCode724FindPivotIndex
{
    public IList<IList<int>> FindDifference(int[] nums1, int[] nums2) {
        HashSet<int> first = new HashSet<int>(nums1);
        HashSet<int> second = new HashSet<int>(nums2);
        HashSet<int> overlaps = new HashSet<int>();
        foreach (var num in first)
        {
            if(!second.Contains(num))
                continue;
            overlaps.Add(num);
        }

        foreach (var num in overlaps)
        {
            first.Remove(num);
            second.Remove(num);
        }

        return [[..first], [..second]];
    }
}
