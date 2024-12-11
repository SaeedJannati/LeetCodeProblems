using System.Text;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode51NQueens : BaseProblemClass
{
    public IList<IList<string>> SolveNQueens(int n)
    {
        if (n == 1)
            return [["Q"]];
        List<List<List<int>>> boards = [];

        for (int i = 0; i < n; i++)
        {
            var board = Enumerable.Range(0, n).Select(_ => Enumerable.Repeat(0, n).ToList())
                .ToList();
            Place(0, i, board, n);
            boards.Add(board);
        }

        for (int i = 1; i < n; i++)
        {
            AddLayer(i, boards, n);
        }

        IList<IList<string>> result = [];
        for (int i = 0, e = boards.Count; i < e; i++)
        {
            List<string> answer = new List<string>();
            for (int j = 0; j < n; j++)
            {
                StringBuilder builder = new StringBuilder();
                for (int k = 0; k < n; k++)
                {
                    if (boards[i][k][j] == 1)
                    {
                        builder.Append('Q');
                        continue;
                    }

                    builder.Append('.');
                }

                answer.Add(builder.ToString());
            }

            result.Add(answer);
        }

        return result;
    }

    private void AddLayer(int rowNum, List<List<List<int>>> boards, int n)
    {
        bool placed = false;
        for (int i = boards.Count - 1; i >= 0; i--)
        {
            placed = false;
            List<List<int>> temp = new();
            DeepCopy(boards[i], temp);
            for (int j = 0; j < n; j++)
            {
                if (temp[rowNum][j] != 0)
                    continue;
                if (!placed)
                {
                    placed = true;
                    Place(rowNum, j, boards[i], n);
                    continue;
                }

                List<List<int>> newTemp = new();
                DeepCopy(temp, newTemp);
                Place(rowNum, j, newTemp, n);
                boards.Add(newTemp);
            }

            if (!placed)
                boards.Remove(boards[i]);
        }
    }

    private void DeepCopy(List<List<int>> original, List<List<int>> copy)
    {
        for (int i = 0, e = original.Count; i < e; i++)
        {
            copy.Add([..original[i]]);
        }
    }

    private void Place(int row, int column, List<List<int>> board, int n)
    {
        board[row][column] = 1;
        int newRow = 0;
        int newColumn = 0;
        for (int i = 0; i < n; i++)
        {
            if (board[row][i] == 0)
                board[row][i] = -1;
            if (board[i][column] == 0)
                board[i][column] = -1;
            newRow = row + i;
            newColumn = column + i;
            if (newRow < n && newColumn < n)
                if (board[newRow][newColumn] == 0)
                    board[newRow][newColumn] = -1;
            newRow = row - i;
            newColumn = column - i;
            if (newRow >= 0 && newColumn >= 0)
                if (board[newRow][newColumn] == 0)
                    board[newRow][newColumn] = -1;
            newRow = row + i;
            if (newRow < n && newColumn >= 0)
                if (board[newRow][newColumn] == 0)
                    board[newRow][newColumn] = -1;
            newRow = row - i;
            newColumn = column + i;
            if (newRow >= 0 && newColumn < n)
                if (board[newRow][newColumn] == 0)
                    board[newRow][newColumn] = -1;
        }
    }

    public override void Run()
    {
        int n = 5;
        Console.WriteLine(JsonSerializer.Serialize(SolveNQueens(n)));
    }
}