namespace LeetCodeProblems.Problems;

public class LeetCode2551PutMarblesInBags : BaseProblemClass
{
    # region with sort

    public long PutMarbles(int[] weights, int k)
    {
        if (k == 1)
            return 0;
        int length = weights.Length;
        if (length == 1)
            return 0;
        if (k == length)
            return 0;
        for (int i = 0; i < length - 1; i++)
        {
            weights[i]  += weights[i + 1];
        }
        weights[length - 1] =0;
        Array.Sort(weights);
        long delta = 0;
        for (int i = 0; i < k - 1; i++)
        {
            delta+= weights[length-1-i]-weights[i+1];
        }

        return delta;
    }

    #endregion

    #region with heap

    // public long PutMarbles(int[] weights, int k)
    // {
    //     if (k == 1)
    //         return 0;
    //     int length = weights.Length;
    //     if (length == 1)
    //         return 0;
    //     if (k == length)
    //         return 0;
    //     PriorityQueue<long, long> heap = new();
    //     int adjacentElementsSum = 0;
    //     for (int i = 0; i < length - 1; i++)
    //     {
    //         adjacentElementsSum = weights[i] + weights[i + 1];
    //         heap.Enqueue( adjacentElementsSum, -adjacentElementsSum);
    //     }
    //
    //     long maxSum = 0;
    //     for (int i = 0; i < k - 1; i++)
    //     {
    //         var sliceInfo = heap.Dequeue();
    //         maxSum += sliceInfo;
    //     }
    //
    //     long minSum = 0;
    //     heap.Clear();
    //     for (int i = 0; i < length - 1; i++)
    //     {
    //         adjacentElementsSum = weights[i] + weights[i + 1];
    //         heap.Enqueue(adjacentElementsSum, adjacentElementsSum);
    //     }
    //     for (int i = 0; i < k - 1; i++)
    //     {
    //         var sliceInfo = heap.Dequeue();
    //         minSum += sliceInfo;
    //     }
    //     return maxSum-minSum;
    // }

    #endregion


    public override void Run()
    {
        int[] weights = [1, 3, 5, 1];
        int k = 2;
        Console.WriteLine(PutMarbles(weights, k));
    }
}