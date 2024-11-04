namespace LeetCodeProblems.Problems;

public class LeetCode274HIndex : BaseProblemClass
{
    public int HIndex(int[] citations)
    {
        int count = 0;
        var dict = new Dictionary<int, int>(count);
        int min = citations[0];
        foreach (var num in citations)
        {
            if (num == 0)
                continue;
            if (num < min)
                min = num;
            count++;
            if (dict.TryAdd(num, 1))
                continue;
            dict[num]++;
        }

        if (count == 0)
            return 0;
        if (min >= count)
            return count;
        int outPut = 0;
        int citationsBefore = 0;
        for (int i = min, e = citations.Length; i < e; i++)
        {
            if (count - citationsBefore >= i)
                outPut = i;
            if (dict.ContainsKey(i))
                citationsBefore += dict[i];
        }

        return outPut;
    }

    public override void Run()
    {
        int[] input = [100];
        Console.WriteLine(HIndex(input));
    }
}