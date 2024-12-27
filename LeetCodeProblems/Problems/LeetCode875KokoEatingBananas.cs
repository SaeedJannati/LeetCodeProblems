namespace LeetCodeProblems.Problems;

public class LeetCode875KokoEatingBananas : BaseProblemClass
{
    public int MinEatingSpeed(int[] piles, int h)
    {
        Array.Sort(piles);
        if (h == piles.Length)
            return piles[^1];
        if (piles.Length == 1)
        {
            if (h > piles[^1])
                return 1;
            return piles[0]/h   + (piles[0] %h  == 0 ? 0 : 1);
        }

        int begin = 1;
        int end = piles[^1];
        int mid = 0;
        int spent = 0;
        int min = int.MaxValue;
        while (begin <= end && begin > 0)
        {
            mid = (begin + end) / 2;
            spent = 0;
            foreach (var t in piles)
            {
                spent += t / mid;
                if (t % mid != 0)
                    spent++;
                if (spent > h)
                    break;
            }

            if (spent <= h)
                if (mid < min)
                    min = mid;
            if (spent > h)
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return min;
    }

    public override void Run()
    {
        int[] input = [312884470];
        int h = 312884469;
        Console.WriteLine(MinEatingSpeed(input, h));
    }
}