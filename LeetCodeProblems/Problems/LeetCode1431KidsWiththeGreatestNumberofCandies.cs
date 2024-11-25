namespace LeetCodeProblems.Problems;

public class LeetCode1431KidsWiththeGreatestNumberofCandies
{
    public IList<bool> KidsWithCandies(int[] candies, int extraCandies) 
    {
        int maxCandies = int.MinValue;
        int length=candies.Length;
        for (int i = 0; i < length; i++)
        {
            if(candies[i] > maxCandies)
                maxCandies = candies[i];
        }
        IList<bool> result=new List<bool>(length);
        for (int i = 0; i < length; i++)
        {
            result.Add(candies[i] +extraCandies>=maxCandies);
        }
        return result;
    }
    
    //Using C# methods
    // public IList<bool> KidsWithCandies(int[] candies, int extraCandies) 
    // {
    //     int maxCandies = candies.Max();
    //     IList<bool> result = candies.Select(i=>i+extraCandies>=maxCandies).ToList();
    //     return result;
    // }
}