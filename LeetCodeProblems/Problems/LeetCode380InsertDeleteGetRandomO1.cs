namespace LeetCodeProblems.Problems;

public class LeetCode380InsertDeleteGetRandomO1
{
    private HashSet<int> collection = [];
    private List<int> list = [];
    private Random _random=new(DateTime.Now.Millisecond);
    // public RandomizedSet() {
    //     
    // }
    
    public bool Insert(int val)
    {
        if (collection.Contains(val))
            return false;
        collection.Add(val);
        list.Add(val);
        return true;
    }
    
    public bool Remove(int val)
    {
        if (!collection.Contains(val))
            return false;
        collection.Remove(val);
        list.Remove(val);
        return true;
    }
    
    public int GetRandom() {
     return list[_random.Next(0, list.Count)];        
    }
}