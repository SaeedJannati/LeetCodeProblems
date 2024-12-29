namespace LeetCodeProblems.Problems;

public class LeetCode1639NumberOfWaysToFormATargetStringGivenADictionary: BaseProblemClass
{
    public int NumWays(string[] words, string target)
    {
        int wordLength = words[0].Length;
        int targetLength = target.Length;
        if (targetLength > wordLength)
            return 0;
        List<Dictionary<char, int>> wordDictionary = new(wordLength);
        for (int i = 0; i < wordLength; i++)
        {
            wordDictionary.Add([]); 
        }

        for (int i = 0; i < wordLength; i++)
        {
            foreach (var word in words)
            {
                if (!wordDictionary[i].TryAdd(word[i], 1))
                    wordDictionary[i][word[i]]++;
            }
        }

        int moduloNum = 1_000_000_000 + 7;
        int[,] dp = new int[targetLength,wordLength];
        int current = 0;
        wordDictionary[0].TryGetValue(target[0], out current);
        dp[0, 0] = current%moduloNum;
        for (int i = 1; i < wordLength; i++)
        {
            wordDictionary[i].TryGetValue(target[0], out current);
            dp[0, i] = (dp[0, i-1]%moduloNum + current% moduloNum) % moduloNum;
        }

        for (int i = 1; i < targetLength; i++)
        {
            wordDictionary[i].TryGetValue(target[i],out current);
            
            dp[i, i] = (int)((dp[i - 1, i - 1] % moduloNum * (long)current % moduloNum) % moduloNum);
            for (int j = i + 1; j < wordLength; j++)
            {
                wordDictionary[j].TryGetValue(target[i], out current);
                dp[i, j] = (int)(((dp[i - 1, j - 1] % moduloNum * (long)current % moduloNum) + dp[i, j - 1]) % moduloNum);
            }
        }
        return dp[targetLength-1, wordLength-1]%moduloNum;
    }

    public override void Run()
    {
        string[] words = ["abba","baab"];
        string target ="babbbb";
        Console.WriteLine(NumWays(words, target));
    }
}