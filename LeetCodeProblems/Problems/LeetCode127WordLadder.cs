namespace LeetCodeProblems.Problems;

public class LeetCode127WordLadder : BaseProblemClass
{
    public int LadderLength(string beginWord, string endWord, IList<string> wordList)
    {
        HashSet<string> wordSet = [..wordList];
        HashSet<string> checkedWords = [];
        if (!wordSet.Contains(endWord))
            return 0;
        if (wordSet.Add(beginWord))
        {
            wordList.Add(beginWord);
        }

        Graph graph = new();
        int length = wordList.Count;
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (!AreAdjacent(wordList[i], wordList[j]))
                    continue;
                graph.AddEdge(wordList[i], wordList[j]);
                graph.AddEdge(wordList[j], wordList[i]);
            }
        }

        Queue<string> queue = new();
        Queue<string> nextLayer = new();
        queue.Enqueue(beginWord);
        var current = beginWord;
        int counter = 1;
        while (queue.Count > 0)
        {
            while (queue.Count > 0)
            {
                current = queue.Dequeue();
                if (current == endWord)
                    return counter;
                if (!graph.adjacencyList.TryGetValue(current, out var value)) 
                    continue;
                foreach (var str in value)
                {
                    if(!checkedWords.Add(str))
                        continue;
                    nextLayer.Enqueue(str);
                }
            }

            while (nextLayer.Count > 0)
            {
                queue.Enqueue(nextLayer.Dequeue());
            }

            counter++;
        }

        return 0;
    }

    private bool AreAdjacent(string first, string second)
    {
        if (first.Length != second.Length)
            return false;
        var difference = 0;
        for (int i = 0, e = first.Length; i < e; i++)
        {
            if (first[i] != second[i])
                difference++;
            if (difference > 1)
                return false;
        }

        if (difference == 0)
            return false;
        return true;
    }

    public class Graph()
    {
        public readonly Dictionary<string, HashSet<string>> adjacencyList = [];

        public void AddEdge(string from, string to)
        {
            if (adjacencyList.TryGetValue(from, out var value))
            {
                value.Add(to);
                return;
            }

            adjacencyList[from] = [to];
        }
    }

    public override void Run()
    {
        var begin = "hot";
        var end = "dog";
        IList<string> wordList = ["hot", "dog"];
        Console.WriteLine(LadderLength(begin, end, wordList));
    }
}