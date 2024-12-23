namespace LeetCodeProblems.Problems;

public class LeetCode2423RemoveLetterToEqualizeFrequency : BaseProblemClass
{
    public bool EqualFrequency(string word)
    {
        Dictionary<char, int> charFrequency = new Dictionary<char, int>(26);
        Dictionary<int, int> frequencyCount = [];
        foreach (var character in word)
        {
            if (!charFrequency.TryAdd(character, 1))
                charFrequency[character]++;
        }

        foreach (var pair in charFrequency)
        {
            if (!frequencyCount.TryAdd(pair.Value, 1))
                frequencyCount[pair.Value]++;
        }

        if (frequencyCount.Count > 2)
            return false;


        var first = frequencyCount.First();
        if (frequencyCount.Count == 1)
        {
            if (first.Key == 1 || first.Value==1)
                return true;
            return false;
        }

        var second = frequencyCount.Last();
        
        if (first.Value == 1 )
        {
            if (first.Key == 1)
                return true;
            if(first.Key - second.Key==1)
                return true;
        }
        if (second.Value == 1 )
        {
            if (second.Key == 1)
                return true;
            if(second.Key-first.Key  == 1)
                return true;
        }
        return false;
    }

    public override void Run()
    {
        var input = "aaaabbbbccc";
        Console.WriteLine(EqualFrequency(input));
    }
}