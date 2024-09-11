namespace LeetCodeProblems.Problems;

public class LeetCode215KthLargestElementInAnArray: BaseProblemClass
{
    public override void Run()
    {
        
    }
    public int FindKthLargest(int[] nums, int k)
    {
        var priorityQueue = new PriorityQueue<int,int>(nums.Length);
        foreach (var num in nums)
        {
            priorityQueue.Enqueue(num, num);
        }
        for(int i=0;i<k-1;i++)
            priorityQueue.Dequeue();
        return priorityQueue.Dequeue();
    }

}