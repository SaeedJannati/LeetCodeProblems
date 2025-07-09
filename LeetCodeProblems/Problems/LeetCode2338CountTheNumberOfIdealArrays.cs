using Newtonsoft.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2338CountTheNumberOfIdealArrays: BaseProblemClass
{
    public int IdealArrays(int n, int maxValue)
    {
        int mod = 1_000_000_007;
        var primes=GetPrimesUnder(maxValue);
       Console.WriteLine(JsonConvert.SerializeObject(primes));
        return 1;
    }

    Dictionary<int,int> GetPrimesUnder(int maxValue)
    {
        Dictionary<int,int> primes = [];
        HashSet<int> removed = [];
        var logMax=Math.Log10(maxValue);
        int counter;
        for (int i = 2; i <= maxValue; i++)
        {
            if(!removed.Add(i))
                continue;
            primes[i]=(int)(logMax / Math.Log10(i));
            counter=2;
            while (counter*i<=maxValue)
            {
                removed.Add(i*counter);
                counter++;
            }
        }

        return primes;
    }
    public override void Run()
    {
        int n = 2;
        int maxValue = 100;
        Console.WriteLine(IdealArrays(n, maxValue));
    }
}