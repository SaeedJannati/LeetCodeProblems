namespace LeetCodeProblems.Problems;

public class LeetCode605CanPlaceFlowers
{
    public bool CanPlaceFlowers(int[] flowerbed, int n)
    {
        if (n == 0)
            return true;
        int length = flowerbed.Length;
        for (int i = 0; i < length; i++)
        {
            if (flowerbed[i] != 1)
                continue;
            if (PlantFlower(i, flowerbed, length))
                i++;
        }

        for (int i = 0; i < length; i++)
        {
            if (flowerbed[i] != 0)
                continue;
            PlantFlower(i, flowerbed, length);
            n--;
            if (n == 0)
                return true;
            i++;
        }

        return n == 0;
    }

    private bool PlantFlower(int index, int[] flowerbed, int length)
    {
        if (index < length - 1)
            if (flowerbed[index + 1] == 0)
                flowerbed[index + 1] = -1;
        if (index > 0)
            if (flowerbed[index - 1] == 0)
            {
                flowerbed[index - 1] = -1;
                return true;
            }


        return false;
    }
}