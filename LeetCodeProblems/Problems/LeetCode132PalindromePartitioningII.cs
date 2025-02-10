namespace LeetCodeProblems.Problems;

public class LeetCode132PalindromePartitioningII : BaseProblemClass
{
    public int MinCut(string s)
    {
        int length = s.Length;
        var palindromeDp = new bool[length, length];
        Dictionary<int, HashSet<int>> adjPlus = [];
        for (int i = 0; i < length; i++)
        {
            palindromeDp[i, i] = true;
            adjPlus[i]= [i];
        }

        for (int i = 0; i < length - 1; i++)
        {
            if (s[i] != s[i + 1])
                continue;
            palindromeDp[i, i + 1] = true;
            adjPlus[i].Add(i + 1);
        }

        for (int j = 2; j < length; j++)
        {
            for (int i = 0; i < length - j; i++)
            {
                if (!palindromeDp[i + 1, i + j - 1])
                    continue;
                if (s[i] != s[i + j])
                    continue;
                palindromeDp[i, i + j] = true;
                adjPlus[i].Add(i+j);
            }
        }
        var visited=new bool[length+1];
        Queue<int> currentLayer = [];
        Queue<int> nextLayer = [];
        currentLayer.Enqueue(0);
        visited[0] = true;
        int cuts = 0;
        int vert = 0;
        while (currentLayer.Count>0) 
        {
            while (currentLayer.Count > 0)
            {
                vert=currentLayer.Dequeue();
                foreach (var node in adjPlus[vert])
                {
                    if (node == length - 1)
                        return cuts;
                    if(visited[node+1])
                        continue;
                    visited[node+1] = true;
                    nextLayer.Enqueue(node+1);
                }
            }

            while (nextLayer.Count>0)
            {
                currentLayer.Enqueue(nextLayer.Dequeue());
            }

            cuts++;
        }
        return cuts;
    }

    public override void Run()
    {
        string s = "bb";
        Console.WriteLine(MinCut(s));
    }
}