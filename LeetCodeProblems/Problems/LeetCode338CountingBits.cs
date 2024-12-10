using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode338CountingBits: BaseProblemClass
{
    public int[] CountBits(int n)
    {
        if (n == 0)
            return [0];
        if (n == 1)
            return [0, 1];
        var bits = new int[(int)Math.Log2(n) + 1];
        var output = new int[n + 1];
        int length = bits.Length;
        for (int i = 0,e=n+1; i < e; i++)
        {
            output[i] = GetOneCount(bits,length);
            AddOne(bits,length);
        }
        return output;
    }

    private int GetOneCount(int[] bits, int length)
    {
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (bits[i]==1)
            {
                counter++;
            }
        }

        return counter;
    }

    private void AddOne(int[] bits,int length)
    {
        for (int i = 0; i < length; i++)
        {
            bits[i] += 1;
            if(bits[i] <=1)
                return;
            bits[i] = 0;
        }

    }

    public override void Run()
    {
        int n = 4;
        Console.WriteLine(JsonSerializer.Serialize(CountBits(n)));
    }
}