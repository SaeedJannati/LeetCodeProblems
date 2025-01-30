namespace LeetCodeProblems.Problems;

public class LeetCode1007MinimumDominoRotationsForEqualRow : BaseProblemClass
{
    public int MinDominoRotations(int[] tops, int[] bottoms)
    {
        int length = tops.Length;
        int[] numCount = new int[7];
        int[,] numsInRows = new int[2, 7];
        bool[,] isInCol = new bool[length, 7];
        for (int i = 0; i < length; i++)
        {
            numCount[tops[i]]++;
            numsInRows[0, tops[i]]++;
            numCount[bottoms[i]]++;
            numsInRows[1, bottoms[i]]++;
            isInCol[i, bottoms[i]] = true;
            isInCol[i, tops[i]] = true;
        }

        int minRowsToTurn = int.MaxValue;

        for (int i = 1; i <= 6; i++)
        {
            if (numCount[i] < length)
                continue;
            bool isInAllCols = true;
            for (int j = 0; j < length; j++)
            {
                if (isInCol[j, i])
                    continue;
                isInAllCols = false;
                break;
            }

            if (!isInAllCols)
                continue;
            int numsToTurn = length - int.Max(numsInRows[0, i], numsInRows[1, i]);
            if (numsToTurn < minRowsToTurn)
                minRowsToTurn = numsToTurn;
        }

        if (minRowsToTurn == int.MaxValue)
            return -1;
        return minRowsToTurn;
    }

    public override void Run()
    {
        int[] tops = [3, 5, 1, 2, 3];
        int[] bottoms = [3, 6, 3, 3, 4];
        Console.WriteLine(MinDominoRotations(tops, bottoms));
    }
}