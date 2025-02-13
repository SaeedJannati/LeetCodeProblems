namespace LeetCodeProblems.Problems;

public class LeetCode3066MinimumOperationsToExceedThresholdValueII : BaseProblemClass
{
    public int MinOperations(int[] nums, int k)
    {
        int length = nums.Length;
        PriorityQueue<long, long> minHeap = new(length);
        for (int i = 0; i < length; i++)
        {
            minHeap.Enqueue(nums[i], nums[i]);
        }

        int counter = 0;
        long firstNum = 0;
        long secondNum = 0;
        long newNum = 0;
        while (minHeap.Count > 1 && minHeap.Peek() < k)
        {
            counter++;
            firstNum = minHeap.Dequeue();
            secondNum = minHeap.Dequeue();
            newNum = Math.Min(firstNum, secondNum);
            newNum *= 2;
            newNum += Math.Max(firstNum, secondNum);
            minHeap.Enqueue(newNum, newNum);
        }

        return counter;
    }

    public override void Run()
    {
        int[] nums = [999999999, 999999999, 999999999];
        int k = 1000000000;
        Console.WriteLine(MinOperations(nums, k));
    }
}