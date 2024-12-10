namespace LeetCodeProblems.Problems;

public class LeetCode933NumberOfRecentCalls
{
    public class RecentCounter
    {
        private readonly Queue<int> _queue = new Queue<int>();

        public RecentCounter()
        {
        }

        public int Ping(int t)
        {
            _queue.Enqueue(t);
            while (t - _queue.Peek() > 3000)
            {
                _queue.Dequeue();
            }

            return _queue.Count;
        }
    }
}