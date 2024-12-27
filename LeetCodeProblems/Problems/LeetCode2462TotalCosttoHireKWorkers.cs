namespace LeetCodeProblems.Problems;

public class LeetCode2462TotalCosttoHireKWorkers : BaseProblemClass
{
    public long TotalCost(int[] costs, int k, int candidates)
    {
        PriorityQueue<int, int> leftQueue = new();
        PriorityQueue<int, int> rightQueue = new();
        int leftIndex = 0;
        int rightIndex = 0;
        int length = costs.Length;
        long totalCost = 0;

        if (candidates * 2 >= length)
        {
            foreach (var cost in costs)
            {
                leftQueue.Enqueue(cost, cost);
            }

            for (int i = 0; i < k; i++)
                totalCost += leftQueue.Dequeue();
            return totalCost;
        }

        for (int i = 0; i < candidates; i++)
        {
            leftQueue.Enqueue(costs[i], costs[i]);
            rightQueue.Enqueue(costs[length - i - 1], costs[length - i - 1]);
        }

        leftIndex = candidates - 1;
        rightIndex = length - candidates;
        int currentCost = 0;
        for (int i = 0; i < k; i++)
        {
            if (leftQueue.Count == 0)
            {
                totalCost += rightQueue.Dequeue();
                continue;
            }

            if (rightQueue.Count == 0)
            {
                totalCost += leftQueue.Dequeue();
                continue;
            }

            if (leftIndex >= rightIndex)
            {
                if (leftQueue.Peek() <= rightQueue.Peek())
                    totalCost += leftQueue.Dequeue();
                else
                    totalCost += rightQueue.Dequeue();
                continue;
            }

            if (leftQueue.Peek() <= rightQueue.Peek())
            {
                totalCost += leftQueue.Dequeue();
                leftIndex++;
                if (leftIndex < rightIndex)
                    leftQueue.Enqueue(costs[leftIndex], costs[leftIndex]);
                continue;
            }

            totalCost += rightQueue.Dequeue();
            rightIndex--;
            if (leftIndex < rightIndex)
                rightQueue.Enqueue(costs[rightIndex], costs[rightIndex]);
        }

        return totalCost;
    }

    public override void Run()
    {
        int[] costs = [17, 12, 10, 2, 7, 2, 11, 20, 8];
        int k = 3;
        int candidates = 4;
        Console.WriteLine(TotalCost(costs, k, candidates));
    }
}