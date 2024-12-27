namespace LeetCodeProblems.Problems;

public class LeetCode118PascalsTriangle
{
    public IList<IList<int>> Generate(int numRows)
    {
        if (numRows == 1)
            return [[1]];
        IList<IList<int>> result = [[1], [1, 1]];
        for (int i = 2; i < numRows; i++)
        {
            IList<int> row = [1];
            for (int j = 0, e = result[^1].Count-1; j < e; j++)
            {
                row.Add(result[^1][j]+result[^1][j+1]);
            }
            row.Add(1);
            result.Add(row);
        }
        return result;
    }
}