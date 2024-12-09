namespace LeetCodeProblems.Problems;

public class LeetCode1207UniqueNumberOfOccurrences
{
    public bool UniqueOccurrences(int[] arr) 
    {
      Dictionary<int,int> dict=new(arr.Length);
      foreach (var num in arr)
      {
          if(!dict.TryAdd(num, 1))
              dict[num]++;
      }
      var occurences = new HashSet<int>(dict.Count);
      foreach (var pair in dict)
      {
          if(!occurences.Add(pair.Value))
              return false;
      }

      return true;
    }
}