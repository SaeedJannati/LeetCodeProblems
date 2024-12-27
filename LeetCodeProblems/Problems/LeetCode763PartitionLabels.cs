using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode763PartitionLabels: BaseProblemClass
{
    public IList<int> PartitionLabels(string s)
    {
        if (s == null || s.Length == 0)
            return [0];
        if (s.Length == 1)
            return [1];
        IList<int> output = new List<int>();
        var length=s.Length;
        Dictionary<char, int> characteMaxPositions = [];
        for (int i = 0; i < length; i++)
        {
            characteMaxPositions[s[i]] = i;
        }

        int startingPoint = 0;
        int endingPoint = 0;
        while (endingPoint<length)
        {
            endingPoint=characteMaxPositions[s[startingPoint]];
            if (endingPoint == startingPoint)
            {
                output.Add(1);
                startingPoint++;
                endingPoint++;
                continue;
            }
            int currentEndingPoint = 0;
            for (int i = startingPoint; i < endingPoint; i++)
            {
                currentEndingPoint=characteMaxPositions[s[i]];
                if(currentEndingPoint>endingPoint)
                    endingPoint=currentEndingPoint;
            }
            output.Add(endingPoint-startingPoint+1);
            startingPoint = endingPoint + 1;
            endingPoint=startingPoint;
        }

        return output;
    }

    public override void Run()
    {
        string input = "ababcbacadefegdehijhklij";
        Console.WriteLine(JsonSerializer.Serialize(PartitionLabels(input)));
    }
}