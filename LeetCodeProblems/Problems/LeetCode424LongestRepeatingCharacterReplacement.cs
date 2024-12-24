namespace LeetCodeProblems.Problems;

public class LeetCode424LongestRepeatingCharacterReplacement : BaseProblemClass
{
    public int CharacterReplacement(string s, int k)
    {
        int firstPointer = 0;
        int secondPointer = 1;
        int length = s.Length;
        int maxLength = 1;
        int currentLength = 1;
        var tracker = new Tracker();
        tracker.Add(s[0]);
        while (secondPointer < length)
        {
            while (secondPointer < length && tracker.maxValue + k>=currentLength)
            {
                tracker.Add(s[secondPointer]);
                currentLength = secondPointer - firstPointer + 1;
                secondPointer++;
                if (currentLength > tracker.maxValue + k)
                    break;
                if (currentLength > maxLength)
                    maxLength = currentLength;
            }

            if (secondPointer > length - 1)
                return maxLength;
            tracker.Add(s[secondPointer]);
            tracker.Remove(s[firstPointer]);
            firstPointer++;
            currentLength = secondPointer - firstPointer + 1;
            secondPointer++;
            if (tracker.maxValue + k >= currentLength)
                if (currentLength > maxLength)
                    maxLength = currentLength;
            
        }

        return maxLength;
    }

    public class Tracker
    {
        public Dictionary<char, int> dict = [];
        public char maxKey = '\0';
        public int maxValue = 0;

        public void Add(char key)
        {
            if (!dict.TryAdd(key, 1))
                dict[key]++;
            if (dict[key] > maxValue)
            {
                maxValue = dict[key];
                maxKey = key;
            }
        }

        public void Remove(char key)
        {
            dict[key]--;
            if (dict[key] == 0)
                dict.Remove(key);
            if (key != maxKey)
                return;
            var data = dict.MaxBy(i => i.Value);
            maxKey = data.Key;
            maxValue = data.Value;
        }
    }


    public override void Run()
    {
        string input = "ABAB";
        int k = 0;
        Console.WriteLine(CharacterReplacement(input, k));
    }
}