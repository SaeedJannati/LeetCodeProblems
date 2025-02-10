namespace LeetCodeProblems.Problems;

public class LeetCode313SuperUglyNumber: BaseProblemClass
{
    public int NthSuperUglyNumber(int n, int[] primes)
    {
        int primesLength = primes.Length;
        int[] primeIndex = new int[primesLength];
        PriorityQueue<int, int> minHeap = new();
        var uglies = new List<int>(n);
        HashSet<int> ugliesAdded = [];
        uglies.Add(1);
        int ugly = 0;
        long newUgly = 0;
        int maxInt = int.MaxValue;
        for (int i = 0; i < primesLength; i++)
        {
            ugly=uglies[primeIndex[i]]*primes[i];
            if(!ugliesAdded.Add(ugly))
                continue;
            minHeap.Enqueue(ugly,ugly);
        }

        int counter = 1;
        while (counter<n)
        {
            ugly=minHeap.Dequeue();
            uglies.Add(ugly);
            for (int i = 0; i < primesLength; i++)
            {
                newUgly = uglies[primeIndex[i]];
                newUgly*= primes[i];
                if(newUgly>maxInt)
                    continue;
                if(ugly!=newUgly)
                    continue;
                primeIndex[i]++;
                long uglyToAdd = uglies[primeIndex[i]];
                uglyToAdd*= primes[i];
                if(uglyToAdd>maxInt)
                    continue;
                int toAdd=(int)uglyToAdd;
                if(!ugliesAdded.Add(toAdd))
                    continue;
                minHeap.Enqueue(toAdd,toAdd);
            }
            counter++;
        }
        return uglies[n-1];
    }

    public override void Run()
    {
        int n = 5911;
        int[] primes = [2, 3, 5, 7];
        Console.WriteLine(NthSuperUglyNumber(n, primes));
    }
}