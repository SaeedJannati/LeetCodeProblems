namespace LeetCodeProblems.Problems;

public class LeetCode295FindMedianfromDataStream : BaseProblemClass
{
    public class MedianFinder
    {
        private PriorityQueue<int, int> left = new();
        private PriorityQueue<int, int> right = new();
        private int totalCount = 0;

        public MedianFinder()
        {
        }

        public void AddNum(int num)
        {
            totalCount++;
            if (left.Count == 0 && right.Count == 0)
            {
                left.Enqueue(num, -num);
                return;
            }

            if (num > left.Peek())
                right.Enqueue(num, num);
            else
                left.Enqueue(num, -num);
            int newNum = 0;
            while (left.Count - right.Count > 1)
            {
                newNum = left.Dequeue();
                right.Enqueue(newNum, newNum);
            }

            while (right.Count - left.Count > 1)
            {
                newNum = right.Dequeue();
                left.Enqueue(newNum, -newNum);
            }
        }

        public double FindMedian()
        {
            if (totalCount == 1)
            {
                return left.Peek();
            }

            if (totalCount % 2 == 1)
            {
                if (left.Count > totalCount / 2)
                    return left.Peek();
                else
                    return right.Peek();
            }

            return (double)(left.Peek() + right.Peek()) / 2;
        }
    }

    public override void Run()
    {
        var medianFinder = new MedianFinder();
        medianFinder.AddNum(1);
        medianFinder.AddNum(2);
        medianFinder.AddNum(3);
        Console.WriteLine(medianFinder.FindMedian());
    }
}