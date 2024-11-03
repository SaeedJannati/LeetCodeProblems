using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode289GameOfLife: BaseProblemClass
{
    public void GameOfLife(int[][] board)
    {
        int height = board.Length;
        int width = board[0].Length;
        int neighbors = 0;
        Queue<int> previous = [];
        for (int i = 0; i < height+2; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i < height)
                {
                    neighbors=GetAliveNeighbors(i,j,board);
                    if (neighbors < 2)
                    {
                        previous.Enqueue(0);
                    }
                    else
                    {
                        switch (neighbors)
                        {
                            case 3:
                                    previous.Enqueue(1);
                                break;
                            case 4:
                                    previous.Enqueue(0);
                                break;
                            default:
                                previous.Enqueue(board[i][j]);
                                break;
                        }
                    }
                }

                if(i-2<0)
                    continue;
                board[i-2][j] = previous.Dequeue();
            }
        }
    }

    private int GetAliveNeighbors(int row, int col, int[][] board)
    {
        int minRow = row > 0 ? row - 1 : 0;
        int maxRow = row < board.Length - 1 ? row + 1 : row;
        int minCol = col > 0 ? col - 1 : 0;
        int maxCol = col < board[0].Length - 1 ? col + 1 : col;
        int aliveNeighbors = 0;
        for (int i = minRow; i <= maxRow; i++)
        {
            for (int j = minCol; j <= maxCol; j++)
            {
                if (board[i][j] == 1)
                    aliveNeighbors++;
                if (aliveNeighbors > 4)
                    return 4;
            }
        }

        if (board[row][col] == 1)
            aliveNeighbors--;
        return aliveNeighbors<4?aliveNeighbors:4;
    }

    public override void Run()
    {
        int[][] board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]];
        GameOfLife(board);
        Console.WriteLine(JsonSerializer.Serialize(board));
    }
}