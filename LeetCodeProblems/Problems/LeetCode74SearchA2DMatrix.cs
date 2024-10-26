namespace LeetCodeProblems.Problems;

public class LeetCode74SearchA2DMatrix : BaseProblemClass
{
    public override void Run()
    {
        int[][] matrix = [[-10, -8, -6, -4, -3], [0, 2, 3, 4, 5], [8, 9, 10, 10, 12]];
        int target = 0;
        Console.WriteLine(SearchMatrix(matrix, target));
    }

    public bool SearchMatrix(int[][] matrix, int target)
    {
        if (matrix.Length == 0)
            return false;
        int row = FindRow(matrix, target);
        if (row >= matrix.Length)
            return false;
        int column = FindColumn(matrix, target, row);
        if (column >= matrix[row].Length)
            return false;
        return matrix[row][column] == target;
    }

    int FindColumn(int[][] matrix, int target, int row)
    {
        int begin = 0;
        int end = matrix[0].Length - 1;
        int mid;
        int newMid;
        while (true)
        {
            mid = (begin + end) / 2;
            if (target == matrix[row][mid])
                return mid;
            if (target > matrix[row][mid])
            {
                begin = mid;
            }
            else
            {
                end = mid;
            }

            newMid = (begin + end) / 2;
            if (newMid == mid)
            {
                if (target > matrix[row][newMid])
                    return newMid + 1;
                return newMid;
            }
        }
    }

    int FindRow(int[][] matrix, int target)
    {
        if (target <= matrix[0][^1])
            return 0;
        int begin = 0;
        int end = matrix.Length - 1;
        int mid = 0;
        int newMid = 0;
        while (true)
        {
            mid = (begin + end) / 2;
            if (target < matrix[mid][^1])
                end = mid;
            else if (target > matrix[mid][^1])
            {
                begin = mid;
            }
            else
            {
                return mid;
            }

            newMid = (begin + end) / 2;
            if (newMid == mid)
            {
                if (target > matrix[newMid][^1])
                    return newMid + 1;
                return newMid;
            }
        }
    }
}