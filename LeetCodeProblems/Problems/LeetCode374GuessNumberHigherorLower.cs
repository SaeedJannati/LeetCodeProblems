namespace LeetCodeProblems.Problems;

public class LeetCode374GuessNumberHigherorLower
{

    private int guess(int num) => 0;
    public int GuessNumber(int n)
    {
        long begin = 0;
        long end = n;
        int mid = 0;
        while (begin <= end)
        {
            mid=(int)((begin + end) / 2);
            if (guess(mid) == 0)
                return mid;
            if(guess(mid)==1)
                begin = mid + 1;
            else
                end = mid - 1;
        }

        return mid;
    }


}