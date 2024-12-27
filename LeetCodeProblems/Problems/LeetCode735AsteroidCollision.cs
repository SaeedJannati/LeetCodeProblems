namespace LeetCodeProblems.Problems;

public class LeetCode735AsteroidCollision : BaseProblemClass
{
    public int[] AsteroidCollision(int[] asteroids)
    {
        Stack<int> positives = [];
        Stack<int> negatives = [];
        for (int i = 0, e = asteroids.Length; i < e; i++)
        {
            int amount = 0;
            switch (asteroids[i])
            {
                case < 0:
                    if (positives.Count == 0)
                    {
                        negatives.Push(asteroids[i]);
                        continue;
                    }

                    
                    while (positives.Count > 0 && asteroids[i] < 0)
                    {
                        if (asteroids[i] + positives.Peek() > 0)
                        {
                            asteroids[i] = 0;
                            break;
                        }

                        amount = positives.Pop();
                        if (amount + asteroids[i] == 0)
                        {
                            asteroids[i] = 0;
                            break;
                        }
                    }

                    if (asteroids[i] < 0)
                        negatives.Push(asteroids[i]);
                    break;
                case > 0:
                    positives.Push(asteroids[i]);

                    break;
            }
        }

        int current = 0;

        int[] result = new int[negatives.Count + positives.Count];

        int negCount = negatives.Count;
        for (int j = 0, e = negatives.Count; j < e; j++)
        {
            result[e - 1 - j] = negatives.Pop();
        }

        for (int i = negCount, e = negCount + positives.Count; i < e; i++)
        {
            result[e - 1 - i + negCount] = positives.Pop();
        }

        return result;
    }

    public override void Run()
    {
        int[] input = [10,2,-5];
        var asteroids = AsteroidCollision(input);
        Console.WriteLine(string.Join(",", asteroids));
    }
}