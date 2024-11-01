namespace LeetCodeProblems.Problems;

public class LeetCode155MinStack
{
    private List<int> list=[];
    SortedList<int,int> sortedList=[];
    private Dictionary<int, int> dict = [];
    public MinStack() {
        
    }
    
    public void Push(int val) {
        list.Add(val);
        if (dict.ContainsKey(val))
        {
            dict[val]++;
            return;
        }

        dict[val] = 1;
        sortedList.Add(val,val);
    }
    
    public void Pop()
    {
        var value = list[^1];
        list.RemoveAt(list.Count - 1);
        dict[value]--;
        if (dict[value] == 0)
        {
            dict.Remove(value);
            sortedList.Remove(value);
        }

    }
    
    public int Top()
    {
        return list[^1];
    }
    
    public int GetMin()
    {
        return sortedList.First().Value;
    }
}