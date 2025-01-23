namespace LeetCodeProblems.Problems;

public class LeetCode89GrayCode
{
    public IList<int> GrayCode(int n)
    {
        int length = 1 << n;
        var result = new List<int>(length);
        for (int i = 0; i < length; i++)
        {
            result.Add(i ^ (i >> 1));
        }

        return result;
    }
}