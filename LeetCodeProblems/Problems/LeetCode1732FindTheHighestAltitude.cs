namespace LeetCodeProblems.Problems;

public class LeetCode1732FindTheHighestAltitude
{
    public int LargestAltitude(int[] gain)
    {
        int currentAltitude = 0;
        int maxAltitude = 0;
        int length = gain.Length;
        for (int i = 0; i < length; i++)
        {
            currentAltitude += gain[i];
            if (currentAltitude > maxAltitude)
                maxAltitude = currentAltitude;
        }

        return maxAltitude;
    }
}