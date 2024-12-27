namespace LeetCodeProblems.Problems;

public class LeetCode2542MaximumSubsequenceScore
{
    public long MaxScore(int[] nums1, int[] nums2, int k)
    {
        Array.Sort(nums2, nums1, Comparer<int>.Create((x, y) => y.CompareTo(x)));
        var lenght = nums1.Length;

        long maxScore = long.MinValue;
        long currentScore = 0;
        PriorityQueue<int, int> heap = new(lenght);
        long baseScore = 0;
        for (int i = 0; i < k - 1; i++)
        {
            heap.Enqueue(nums1[i], nums1[i]);
            baseScore += nums1[i];
        }

        for (int i = k - 1; i < lenght; i++)
        {
            currentScore = (baseScore + nums1[i]) * nums2[i];


            if (baseScore > 0 && nums1[i] > heap.Peek())
            {
                baseScore -= heap.Dequeue();
                heap.Enqueue(nums1[i], nums1[i]);
                baseScore += nums1[i];
            }

            if (maxScore < currentScore)
                maxScore = currentScore;
        }

        return maxScore;
    }
}