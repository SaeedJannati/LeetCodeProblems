namespace LeetCodeProblems.Problems;

public class LeetCode2349DesignANumberContainerSystem
{
    public class NumberContainers
    {
        private Dictionary<int, int> indexToNum = [];
        private Dictionary<int, SortedList <int, int>> numsIndices = [];

        public NumberContainers()
        {
        }

        public void Change(int index, int number)
        {
            if (!indexToNum.ContainsKey(index))
            {
                indexToNum[index] = number;
                if (!numsIndices.ContainsKey(number))
                {
                    numsIndices[number] = new();
                }
                numsIndices[number].Add(index,index);
                return;
            }
            numsIndices[indexToNum[index]].Remove(index);
            if(numsIndices[indexToNum[index]].Count == 0)
                numsIndices.Remove(indexToNum[index]);
            indexToNum[index] = number;
            if (!numsIndices.ContainsKey(number))
            {
                numsIndices[number] = new();
            }
            numsIndices[number].Add(index,index);
        }

        public int Find(int number)
        {
            if (!numsIndices.ContainsKey(number))
                return -1;
            return numsIndices[number].First().Value;
        }
    }
}