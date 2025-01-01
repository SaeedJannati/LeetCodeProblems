using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode59SpiralMatrixII : BaseProblemClass
{
    public int[][] GenerateMatrix(int n)
    {
        int[][] matrix = new int[n][];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
        }

        int rowInit = 0;
        int rowEnd = n - 1;
        int colInit = 0;
        int colEnd = n - 1;
        int counter = 0;
        int maxNumber = n * n;
        int currentRow = 0;
        int currentCol = 0;
        while (counter < maxNumber)
        {
            while (currentCol <= colEnd)
            {
                counter++;
                matrix[currentRow][currentCol] = counter;
                currentCol++;
            }

            currentCol = colEnd;
            rowInit++;
            currentRow = rowInit;
            while (currentRow <= rowEnd)
            {
                counter++;
                matrix[currentRow][currentCol] = counter;
                currentRow++;
            }

            currentRow = rowEnd;
            colEnd--;
            currentCol = colEnd;
            while (currentCol >= colInit)
            {
                counter++;
                matrix[currentRow][currentCol] = counter;
                currentCol--;
            }

            currentCol = colInit;
            rowEnd--;
            currentRow = rowEnd;
            while (currentRow >= rowInit)
            {
                counter++;
                matrix[currentRow][currentCol] = counter;
                currentRow--;
            }

            currentRow = rowInit;
            colInit++;
            currentCol = colInit;
        }

        return matrix;
    }

    public override void Run()
    {
        Console.WriteLine(JsonSerializer.Serialize(GenerateMatrix(3)) );
    }
}