using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode909SnakesAndLadders : BaseProblemClass
{
    public override void Run()
    {
        int[][] input =
        [
            [-1, -1, 27, 13, -1, 25, -1],
            [-1, -1, -1, -1, -1, -1, -1],
            [44, -1, 8, -1, -1, 2, -1],
            [-1, 30, -1, -1, -1, -1, -1],
            [3, -1, 20, -1, 46, 6, -1],
            [-1, -1, -1, -1, -1, -1, 29],
            [-1, 29, 21, 33, -1, -1, -1]
        ];
        Console.WriteLine(SnakesAndLadders(input));
    }

    public int SnakesAndLadders(int[][] board)
    {
        if (board.Length == 0)
            return 1;
        int width = board.Length;
        int totalSize = width * width;
        for (int i = 0; i < width / 2; i++)
        {
            (board[i], board[width - 1 - i]) = (board[width - 1 - i], board[i]);
        }

        for (int i = 1; i < width; i += 2)
        {
            for (int j = 0; j < width / 2; j++)
            {
                (board[i][j], board[i][width - 1 - j]) = (board[i][width - 1 - j], board[i][j]);
            }
        }
        HashSet<int> visited = new();
        Queue<int> cellsToMoveFrom = new();
        Queue<int> nextLayerCells = new();
        cellsToMoveFrom.Enqueue(0);
        visited.Add(0);
        int moveCount = 0;
        int nextValue;
        var posInBoard = GetPosInMatrix(0, width);
        while (cellsToMoveFrom.Count != 0)
        {
            moveCount++;
            while (cellsToMoveFrom.Count != 0)
            {
                var currentLinearPos = cellsToMoveFrom.Dequeue();
                for (int i = 1; i <= 6; i++)
                {
                    nextValue = currentLinearPos + i;
                    if (nextValue >= totalSize - 1)
                        return moveCount;
                    posInBoard = GetPosInMatrix(nextValue, width);
                    if (board[posInBoard.row][posInBoard.col] == -1)
                    {
                        if (visited.Add(nextValue))
                        {
                            nextLayerCells.Enqueue(nextValue);
                        }

                        continue;
                    }

                    if (board[posInBoard.row][posInBoard.col] == totalSize)
                        return moveCount;
                    if (visited.Add(board[posInBoard.row][posInBoard.col] - 1))
                    {
                        nextLayerCells.Enqueue(board[posInBoard.row][posInBoard.col] - 1);
                    }
                }
            }

            while (nextLayerCells.Count != 0)
            {
                cellsToMoveFrom.Enqueue(nextLayerCells.Dequeue());
            }
        }

        return -1;
    }

    (int row, int col) GetPosInMatrix(int value, int width)
    {
        int row = value / width;
        int col = value % width;
        return (row, col);
    }

    int GetValueFromMatrixPos(int row, int column, int width)
    {
        return row * width + column;
    }

    void PrintMatirx(int[][] board)
    {
        Console.WriteLine("Matrix:");
        foreach (var t in board)
        {
            for (int j = 0; j < board[0].Length; j++)
            {
                Console.Write(t[j] + " ");
            }

            Console.WriteLine();
        }
    }
}