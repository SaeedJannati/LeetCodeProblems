namespace LeetCodeProblems.Problems;

public class LeetCode69Sqrtx: BaseProblemClass
{
    public int MySqrt(int x)
    {
        if (x == 1)
            return 1;
        if (x == 0)
            return 0;
        int begin = 0;
        int end = x;
        int mid = 0;
        int newMid = 0;
        while (true)
        {
            mid = (begin + end) / 2;
            if (x/mid==mid)
                return mid;
            if (mid!=0 &&x/mid>mid)
            {
                begin = mid;
            }
            else
            {
                end = mid;
            }

            newMid = (begin+ end) / 2;
            if (newMid == mid)
            {
                if (x/(mid+1)>mid+1)
                    return newMid + 1;
                if (newMid == 0)
                    return newMid;
                if (newMid == 1)
                    return newMid;
                if(x/(mid-1)<mid-1)
                    return newMid - 1;
                return newMid;
            }
        }
    }

    public override void Run()
    {
        int x = 562464195;
        Console.WriteLine(MySqrt(x));
    }
}