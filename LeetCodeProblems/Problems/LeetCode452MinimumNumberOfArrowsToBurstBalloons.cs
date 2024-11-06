using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode452MinimumNumberOfArrowsToBurstBalloons : BaseProblemClass
{
    public int FindMinArrowShots(int[][] points)
    {
        Array.Sort(points, (a, b) => a[1].CompareTo(b[1]));
        int currentShot = points[0][1];
        int currentIndex = 0;
        int shots = 1;
        while (currentIndex < points.Length)
        {
            if (currentShot >= points[currentIndex][0])
            {
                currentIndex++;
                continue;
            }

            currentShot = points[currentIndex][1];
            shots++;
        }

        return shots;
    }
    /// <summary>
    /// my ugly solution
    /// </summary>
    // public int FindMinArrowShots(int[][] points)
    // {
    //     SortedDictionary<int, SortedList<int, int>> balloons = [];
    //     for (int i = 0, e = points.Length; i < e; i++)
    //     {
    //         if (balloons.ContainsKey(points[i][0]))
    //         {
    //             balloons[points[i][0]].TryAdd(points[i][1], points[i][1]);
    //             continue;
    //         }
    //
    //         balloons[points[i][0]] = new();
    //         balloons[points[i][0]].Add(points[i][1], points[i][1]);
    //     }
    //
    //     int counter = 0;
    //     int lastShot = 0;
    //     while (balloons.Count > 0)
    //     {
    //         lastShot = balloons.First().Value.First().Value;
    //
    //         HashSet<int> keysToRemove = [];
    //         HashSet<int> balloonsToRemove = [balloons.First().Key];
    //         
    //         foreach (var pair in balloons)
    //         {
    //             if (balloonsToRemove.Contains(pair.Key))
    //                 continue;
    //             if(pair.Key>lastShot)
    //                 break;
    //             if(pair.Value.First().Value<lastShot)
    //                 lastShot = pair.Value.First().Value;
    //         }
    //         foreach (var pair in balloons)
    //         {
    //             if (balloonsToRemove.Contains(pair.Key))
    //                 continue;
    //             if (pair.Key <= lastShot)
    //             {
    //                 foreach (var value in pair.Value)
    //                 {
    //                     if (value.Value >= lastShot)
    //                         keysToRemove.Add(value.Key);
    //                     else
    //                     {
    //                         break;
    //                     }
    //                 }
    //                 foreach (var key in keysToRemove)
    //                 {
    //                     pair.Value.Remove(key);
    //                 }
    //
    //                 if (pair.Value.Count == 0)
    //                     balloonsToRemove.Add(pair.Key);
    //             }
    //             else
    //                 break;
    //         }
    //
    //         foreach (var key in balloonsToRemove)
    //         {
    //             balloons.Remove(key);
    //         }
    //
    //         counter++;
    //     }
    //
    //     return counter;
    // }

    public override void Run()
    {
        int[][] inputs = [[9, 12], [1, 10], [4, 11], [8, 12], [3, 9], [6, 9], [6, 7]];
        Console.WriteLine(FindMinArrowShots(inputs));
    }
}