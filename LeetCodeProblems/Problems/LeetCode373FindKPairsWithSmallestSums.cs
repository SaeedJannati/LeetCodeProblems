using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode373FindKPairsWithSmallestSums : BaseProblemClass
{
    public override void Run()
    {
        // int[] nums1 = /*[1, 7, 11]*/Enumerable.Range(1, 1000).ToArray();
        //
        // int[] nums2 = /*[2,4,6]*/Enumerable.Range(1, 1000).ToArray();
        int[] nums1 =[1,2];
        int[] nums2 =[1,1];
        var k = 1;
        var result = KSmallestPairs(nums1, nums2, k);
        Console.WriteLine(JsonSerializer.Serialize(result));
    }

    public IList<IList<int>> KSmallestPairs(int[] nums1, int[] nums2, int k)
    {
        PriorityQueue<List<int>, int> queue = new();
        PriorityQueue<int, int> reverseQueue = new();
        int upperBound = (int)Math.Sqrt(k);
        int firstBound = int.Min(nums1.Length, upperBound);
        int secondBound = int.Min(nums2.Length, upperBound);
        
        for (int i = 0; i < firstBound; i++)
        {
            for (int j = 0; j < secondBound; j++)
            {
                queue.Enqueue([nums1[i], nums2[j]], nums1[i] + nums2[j]);
                reverseQueue.Enqueue(nums1[i] + nums2[j], -(nums1[i] + nums2[j]));
            }
        }
        int firstUpperBound=int.Min(nums1.Length,k);
        int secondUpperBound=int.Min(nums2.Length,k);
        for (int i = 0; i < firstUpperBound; i++)
        {
            for (int j = 0; j < secondUpperBound; j++)
            {
                if(i<firstBound && j<secondBound)
                    continue;
                if (queue.Count > k)
                    if (nums1[i] + nums2[j] >= reverseQueue.Peek())
                        continue;
                queue.Enqueue([nums1[i], nums2[j]], nums1[i] + nums2[j]);
                reverseQueue.Enqueue(nums1[i] + nums2[j], -(nums1[i] + nums2[j]));
            }
        }

        IList<IList<int>> result = new List<IList<int>>(k);
        for (int i = 0; i < k; i++)
        {
            result.Add(queue.Dequeue());
        }

        return result;
    }
}