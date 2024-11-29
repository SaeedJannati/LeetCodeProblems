namespace LeetCodeProblems.Problems;

public class LeetCode2336SmallestNumberinInfiniteSet: BaseProblemClass
{
    public class SmallestInfiniteSet
    {
        private readonly SortedList<int, int> _addedBack = new();
        private int currentCounter = 0;

        public SmallestInfiniteSet()
        {
        }

        public int PopSmallest()
        {
            if (_addedBack.Count > 0)
            {
                var item=_addedBack.First();
                _addedBack.Remove(item.Key);
                return item.Value;
            }

            currentCounter++;
            return currentCounter;
        }

        public void AddBack(int num)
        {
            if (num > currentCounter)
                return;
            _addedBack.TryAdd(num, num);
        }
    }

    public override void Run()
    {
        SmallestInfiniteSet smallestInfiniteSet = new();
        var item = 0;
        item = smallestInfiniteSet.PopSmallest();
        item = smallestInfiniteSet.PopSmallest();
        smallestInfiniteSet.AddBack(3);
        item = smallestInfiniteSet.PopSmallest();
        smallestInfiniteSet.AddBack(2);
        item = smallestInfiniteSet.PopSmallest();
        item = smallestInfiniteSet.PopSmallest();
    }
}