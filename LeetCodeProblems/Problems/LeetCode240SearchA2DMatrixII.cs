namespace LeetCodeProblems.Problems;

public class LeetCode240SearchA2DMatrixII : BaseProblemClass
{
    public bool SearchMatrix(int[][] matrix, int target)
    {
        int height = matrix.Length;
        int width = matrix[0].Length;
        return Dfs(matrix, target, 0, 0, height, width);
    }

    private bool Dfs(int[][] matrix, int target, int row, int col, int height,int width )
    {
        if (row >= height || col >= width)
            return false;
        if (matrix[row][col] == int.MinValue)
            return false;
        if (matrix[row][col] == target)
            return true;
        if (matrix[row][col] > target)
            return false;
        matrix[row][col] = int.MinValue;
        if (Dfs(matrix, target, row + 1, col, height, width))
            return true;
        if (Dfs(matrix, target, row, col + 1, height, width))
            return true;
        return false;
    }

    public override void Run()
    {
        int[][] matrix =
            [[1, 1]];
        int target = 0;
        Console.WriteLine(SearchMatrix(matrix, target));
    }
}