using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode126WordLadderII : BaseProblemClass
{
    void Dfs(IList<string> wordList, Dictionary<short, HashSet<short>> adjPlus, IList<IList<string>> result,
        List<short> currentPath, List<bool> visited,List<bool> availablePath, short index,
        int pathLength, short targetIndex)
    {
        if (currentPath.Count > pathLength)
            return;
        if (index == targetIndex)
        {
            AddResult(currentPath, result, wordList);
            return;
        }

        if (!adjPlus.TryGetValue(index, out var edges))
        {
            return;
        }

        foreach (var adj in edges)
        {
            if (visited[adj])
                continue;
            visited[adj] = true;
            if(!availablePath[adj])
                continue;
            currentPath.Add(adj);
            Dfs(wordList, adjPlus, result, currentPath, visited,availablePath, adj, pathLength, targetIndex);
            currentPath.Remove(adj);
            visited[adj] = false;
        }
    }

    public IList<IList<string>> FindLadders(string beginWord, string endWord, IList<string> wordList)
    {
        if (!wordList.Contains(endWord))
            return [];
        var endWordIndex = (short)wordList.IndexOf(endWord);
        short beginWordIndex = 0;
        if (!wordList.Contains(beginWord))
        {
            wordList.Add(beginWord);
            beginWordIndex = (short)(wordList.Count - 1);
        }
        else
        {
            beginWordIndex = (short)wordList.IndexOf(beginWord);
        }

        var wordLength = (short)wordList.Count;
        Dictionary<short, HashSet<short>> adjPlus = new(wordLength);
        for (short i = 0; i < wordLength; i++)
        {
            for (var j = (short)(i + 1); j < wordLength; j++)
            {
                if (!AreAdjacent(wordList[i], wordList[j]))
                    continue;
                if (!adjPlus.ContainsKey(i))
                    adjPlus[i] = [];
                adjPlus[i].Add(j);
                if (!adjPlus.ContainsKey(j))
                    adjPlus[j] = [];
                adjPlus[j].Add(i);
            }
        }

        if (!adjPlus.ContainsKey(endWordIndex))
            return [];
        List<bool> visitedFromBegin = Enumerable.Repeat(false, wordLength).ToList();
        Queue<short> currentLayer = [];
        Queue<short> nextLayer = [];
        int counter = 1;
        currentLayer.Enqueue(beginWordIndex);
        visitedFromBegin[beginWordIndex] = true;
        int pathLength = -1;
        while (currentLayer.Count > 0)
        {
            while (currentLayer.Count > 0)
            {
                short node = currentLayer.Dequeue();
                if (!adjPlus.TryGetValue(node, out var neighbors))
                    continue;
                foreach (var vert in neighbors)
                {
                    if (visitedFromBegin[vert])
                        continue;
                    visitedFromBegin[vert] = true;
                    if (vert == endWordIndex)
                    {
                        pathLength = counter + 1;
                        break;
                    }

                    nextLayer.Enqueue(vert);
                }
            }

            if (pathLength > 0)
                break;
            while (nextLayer.Count > 0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }

            counter++;
        }

        int pathFromBegin = pathLength;

        List<bool> visitedFromEnd = Enumerable.Repeat(false, wordLength).ToList();
        visitedFromEnd[endWordIndex] = true;
        currentLayer = [];
        nextLayer = [];
        counter = 1;
        currentLayer.Enqueue(endWordIndex);
        pathLength = -1;
        while (currentLayer.Count > 0)
        {
            while (currentLayer.Count > 0)
            {
                short node = currentLayer.Dequeue();
                if (!adjPlus.TryGetValue(node, out var neighbors))
                    continue;
                foreach (var vert in neighbors)
                {
                    if (visitedFromEnd[vert])
                        continue;
                    visitedFromEnd[vert] = true;
                    if (vert == beginWordIndex)
                    {
                        pathLength = counter + 1;
                        break;
                    }

                    nextLayer.Enqueue(vert);
                }
            }

            if (pathLength > 0)
                break;
            while (nextLayer.Count > 0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }

            counter++;
        }

        bool fromBegin = pathFromBegin < pathLength;
        pathLength = int.Min(pathFromBegin, pathLength);
        IList<IList<string>> result = [];
        short startIndex = fromBegin ? beginWordIndex : endWordIndex;
        short endIndex = fromBegin ? endWordIndex : beginWordIndex;
        List<bool> visitedFromBothSides = Enumerable.Repeat(false, wordLength).ToList();
        for (int i = 0; i < wordLength; i++)
        {
            visitedFromBothSides[i] = visitedFromBegin[i] && visitedFromEnd[i];
        }

        visitedFromBegin = Enumerable.Repeat(false, wordLength).ToList();
        visitedFromBegin[startIndex] = true;
        Dfs(wordList, adjPlus, result, [startIndex], visitedFromBegin,visitedFromBothSides, startIndex, pathLength, endIndex);

        if (!fromBegin)
            for (int i = 0; i < result.Count; i++)
            {
                result[i] = [..result[i].Reverse()];
            }

        return result;
    }

    void AddResult(List<short> res, IList<IList<string>> result, IList<string> wordList)
    {
        var match = res.Select(index => wordList[index]).ToList();
        result.Add(match);
    }

    bool AreAdjacent(string first, string second)
    {
        int difference = 0;
        int length = first.Length;
        for (int i = 0; i < length; i++)
        {
            if (first[i] != second[i])
            {
                difference++;
                if (difference > 1)
                    return false;
            }
        }

        return difference == 1;
    }

    public override void Run()
    {
        IList<string> wordList =
        ["a", "b", "c"];
        string beginWord = 
        "a";
        string endWord = 
        "c";
        Console.WriteLine(JsonSerializer.Serialize(FindLadders(beginWord, endWord, wordList)));
    }
}