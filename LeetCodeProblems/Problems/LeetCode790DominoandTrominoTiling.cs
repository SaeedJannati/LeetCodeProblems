namespace LeetCodeProblems.Problems;

public class LeetCode790DominoandTrominoTiling
{
    public int NumTilings(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int[] dpStraight = new int[n + 1];
        int[] dpJagged = new int[n + 1];
        dpStraight[0] = 0;
        dpStraight[1] = 1;
        dpStraight[2] = 2;
        dpJagged[1] = 0;
        dpJagged[2] = 1;
        int hashBase = (int)Math.Pow(10, 9) + 7;
        for (int i = 3; i < n + 1; i++)
        {
            dpStraight[i] = ((dpStraight[i - 1] + dpStraight[i - 2])%hashBase + (2 * dpJagged[i - 1]%hashBase)%hashBase)%hashBase;
            dpJagged[i] = (dpStraight[i - 2] + dpJagged[i - 1])%hashBase;
        }

        return dpStraight[^1];
    }
}