using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode77Combinations : BaseProblemClass
{
    public override void Run()
    {
        var n = 4;
        var k = 4;
        var outPut = Combine(n, k);
        Console.WriteLine(JsonSerializer.Serialize(outPut));
    }

    public IList<IList<int>> Combine(int n, int k)
    {
        var outPut = new List<IList<int>>();
        if (n == 0 || k == 0)
            return outPut;
        if (k > n)
            return outPut;
        for (var currentDigit = 0; currentDigit < k; currentDigit++)
        {
            if (currentDigit == 0)
            {
                for (var i = 1; i <= n - k + 1; i++)
                {
                    outPut.Add([i]);
                }
                continue;
            }
            for (int i = 0, e = outPut.Count; i < e; i++)
            {
                if (outPut[i].Count >= k) continue;
                for (var j = outPut[i][^1] + 2; j <= n - k + currentDigit + 1; j++)
                {
                    var newList = new List<int>(outPut[i]) { j };
                    outPut.Add(newList);
                }

                if (outPut[i][^1] + 1 > n - k + currentDigit + 1) continue;
                outPut[i].Add(outPut[i][^1] + 1);
            }
        }
        return outPut;
    }


    //Recursive Approach
    // just call  this in the combine method with current digit as 0
    // void AddLayer(IList<IList<int>> outPut, int n, int k, int currentDigit)
    // {
    //     if(currentDigit>k)
    //         return;
    //     if (currentDigit == 0)
    //     {
    //         for (int i = 1; i <= n-k+1; i++)
    //         {
    //             outPut.Add([i]);
    //         }
    //         
    //         AddLayer(outPut,n,k,1);
    //     }
    //     else
    //     {
    //       
    //         for (int i = 0,e=outPut.Count; i < e; i++)
    //         {
    //             if(outPut[i].Count>=k)
    //                 continue;
    //             for (int j = outPut[i][^1]+2; j <= n-k+currentDigit+1; j++)
    //             {
    //                 var newList = new List<int>(outPut[i]) { j };
    //                 outPut.Add(newList);
    //             }
    //             if(outPut[i][^1]+1>n-k+currentDigit+1)
    //                 continue;
    //             outPut[i].Add(outPut[i][^1]+1);
    //         }
    //         AddLayer(outPut,n,k,currentDigit+1);
    //     }
    // }
}