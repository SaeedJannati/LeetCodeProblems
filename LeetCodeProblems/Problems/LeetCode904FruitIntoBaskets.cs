namespace LeetCodeProblems.Problems;

public class LeetCode904FruitIntoBaskets : BaseProblemClass
{
    public int TotalFruit(int[] fruits)
    {
        int length = fruits.Length;
        if (length <= 2)
            return length;
        int firstIndex = 0;
        int secondIndex = 1;
        Dictionary<int, int> fruitDict = [];
        fruitDict[fruits [firstIndex]] = 1;
        int maxLength = 0;
        int currentLength = 0;
        while (secondIndex < length)
        {
            while (fruitDict.Count <= 2 && secondIndex < length )
            {
                if (!fruitDict.ContainsKey(fruits[secondIndex]))
                {
                    fruitDict[fruits[secondIndex ]] = 1;
                    if (fruitDict.Count > 2)
                    {
                        secondIndex++;
                        break;
                    }
                }
                else
                {
                    fruitDict[fruits[secondIndex]]++;
                }
      
                if (fruitDict.Count <= 2)
                {
                    currentLength = secondIndex - firstIndex + 1;
                    if (currentLength > maxLength)
                        maxLength = currentLength;
                }
                secondIndex++;
            }

            while (fruitDict.Count > 2)
            {
                fruitDict[fruits[firstIndex]]--;
                if (fruitDict[fruits[firstIndex]] == 0)
                    fruitDict.Remove(fruits[firstIndex]);
                firstIndex++;
            }
        }

        return maxLength;
    }

    public override void Run()
    {
        int[] fruits = [0, 1, 2];
            // [3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]; 
            // [1, 2, 3, 2, 2];
            // [0, 1, 2, 2];
            // [1, 2, 1];
        Console.WriteLine(TotalFruit(fruits));
    }
}