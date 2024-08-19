using System.Net;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode15ThreeSum : BaseProblemClass
{
    public override void Run()
    {
        int[] input = [-1, 0, 1, 2, -1, -4];
        var outPut = ThreeSum(input);
        Console.WriteLine(JsonSerializer.Serialize(outPut));
    }

    private IList<IList<int>> ThreeSumHashMap(int[] nums)
    {
        IList<IList<int>> output = [];
        var input = nums.ToList();
        input.Sort();
        var dict = new Dictionary<int, int>(input.Count);
        for (int i = 0, e = input.Count; i < e; i++)
        {
            if (dict.ContainsKey(input[i]))
            {
                dict[input[i]]++;
                continue;
            }

            dict[input[i]] = 1;
        }

        var lastElement = 0;
        for (int i = 0, e = input.Count; i < e; i++)
        {
            dict[input[i]]--;
            if (dict[input[i]] == 0)
                dict.Remove(input[i]);
            if (i > 0)
                if (input[i] == lastElement)
                    continue;
            lastElement = input[i];
            for (int j = i + 1; j < e; j++)
            {
                if (j < e - 2)
                    if (input[j] == input[j + 1])
                        continue;

                if (dict.ContainsKey(-input[i] - input[j]))
                {
                    if (input[j] == -input[i] - input[j])
                    {
                        if (dict[input[j]] == 1)
                            continue;
                    }

                    if (-input[j] - input[i] > input[j])
                        output.Add([input[i], input[j], -input[i] - input[j]]);
                    if (-input[j] - input[i] == input[j])
                        if (j == e - 1)
                            output.Add([input[i], input[j], -input[i] - input[j]]);
                        else if (input[j + 1] != input[j])
                            output.Add([input[i], input[j], -input[i] - input[j]]);
                }
            }
        }

        return output;
    }

    public IList<IList<int>> ThreeSum(int[] nums)
    {
        IList<IList<int>> output = [];
        var input = nums.ToList();
        input.Sort();
        var firstPointer = 0;
        var secondPointer = 0;
        var sum = 0;
        var lastNum = 0;
        var newSecond = 0;
        var newFirst = 0;
        for (int i = 0, e = input.Count; i < e; i++)
        {
            if (i > 0)
                if (input[i] == lastNum)
                    continue;
            lastNum = input[i];
            firstPointer = i + 1;
            secondPointer = e - 1;
            if (firstPointer >= secondPointer)
                continue;
            while (firstPointer < secondPointer)
            {
                sum = input[i] + input[firstPointer] + input[secondPointer];
                if (sum == 0)
                {
                    output.Add([input[i], input[firstPointer], input[secondPointer]]);
                    newFirst = firstPointer + 1;
                    while (newFirst < secondPointer)
                    {
                        if (input[newFirst] == input[firstPointer])
                        {
                            newFirst++;
                            continue;
                        }
                        break;
                    }
                    firstPointer=newFirst;
                    newSecond = secondPointer - 1;
                    while (newSecond>firstPointer)
                    {
                        if (input[newSecond] == input[secondPointer])
                        {
                            newSecond--;
                            continue;
                        }
                        break;
                    }
                    secondPointer = newSecond;
                    continue;
                }
                if (sum > 0)
                {
                    secondPointer--;
                    continue;
                }
                firstPointer++;
            }
        }
        return output;
    }
}