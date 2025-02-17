namespace LeetCodeProblems.Problems;

public class LeetCode1079LetterTilePossibilities: BaseProblemClass
{
    public int NumTilePossibilities(string tiles)
    {
        var tileArray = tiles.ToCharArray();
        int length = tileArray.Length;
        HashSet<string> sequences = [];
        bool[] visited = new bool[length];
        List<char> letters = new List<char>(length);
        for (int i = 0; i < length; i++)
        {
            if(!sequences.Add($"{tileArray[i]}"))
                continue;
            letters=[tileArray[i]];
            BackTrack(tileArray, visited,sequences,letters,length,i);
        }

        
        return sequences.Count;
    }

    void BackTrack(char[] tiles, bool[] visited, HashSet<string> sequences, List<char> current, int length, int index)
    {
        visited[index] = true;
        for (int i = 0; i < length; i++)
        {
            if (visited[i])
                continue;
            current.Add(tiles[i]);
            int indexToRemove = current.Count - 1;
            if (sequences.Add(new string(current.ToArray())))
            {
                BackTrack(tiles, visited, sequences, current, length, i);
            }

            current.RemoveAt(indexToRemove);
        }

        visited[index] = false;
    }

    public override void Run()
    {
        string tiles = "V";
        Console.WriteLine(NumTilePossibilities(tiles));
    }
}