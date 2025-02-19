namespace LeetCodeProblems.Problems;

public class LeetCode1415TheKthLexicographicalStringOfAllHappyStringsOfLengthN: BaseProblemClass
{
    public string GetHappyString(int n, int k)
    {
        int counter = 0;
        char[] permutation = new char[n];
        char[] pool = ['a', 'b', 'c'];
        bool found = false;
        foreach (var c in pool)
        {
            permutation[0] = c;
            if (Backtrack(permutation, pool, n, k, 1, ref counter))
            {
                found = true;
                break;
            }
        }

        if (!found)
            return "";
        return new string(permutation);
    }

    private bool Backtrack(char[] permutation,char[] pool, int n, int k, int index, ref int counter)
    {
        if (index == n)
        {
            counter++;
            return counter == k;
        }

        foreach (var c in pool)
        {
            if(c==permutation[index-1])
                continue;
            permutation[index] = c;
            if(Backtrack(permutation, pool, n, k, index+1, ref counter))
                return true;
        }
        return false;
    }

    public override void Run()
    {
        int n = 3;
        int k = 9;
        Console.WriteLine(GetHappyString(n, k));
    }
}