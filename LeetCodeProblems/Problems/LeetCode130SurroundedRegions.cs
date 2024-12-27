using System.Text;
using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode130SurroundedRegions: BaseProblemClass
{
    private bool surrounded;
    public void Solve(char[][] board)
    {
        var boardVisiting = new bool[board.Length][];
        var area = new HashSet<(int row, int column)>();
        for (int i = 0, e = board.Length; i < e; i++)
        {
            boardVisiting[i] = new bool[board[i].Length];
        }

        for (int i = 0, e = board.Length; i < e; i++)
        {
            for (int j = 0, f = board[0].Length; j < f; j++)
            {
                if (boardVisiting[i][j])
                    continue;
                if (board[i][j] == 'X')
                    continue;
                area = [];
                surrounded = true;
                CheckForSurround(board, boardVisiting, area, i, j);
               if(! surrounded)
                   continue;
               foreach (var value in area)
               {
                   board[value.row][value.column] = 'X';
               }
            }
        }
    }

    private void CheckForSurround(char[][] board, bool[][] boardVisiting, HashSet<(int row, int column)> area, int row,
        int column)
    {
        if (boardVisiting[row][column])
            return ;
        var outPut = true;
        boardVisiting[row][column] = true;
        area.Add((row, column));
        if (row == 0 || column == 0 || row == board.Length - 1 || column == board[0].Length - 1)
        {
            surrounded=false;
        }
        if(row<board.Length-1 && board[row+1][column] == 'O' )
             CheckForSurround(board, boardVisiting, area, row +1, column);
        if(row>0&& board[row-1][column] == 'O')
            CheckForSurround(board, boardVisiting, area, row - 1, column );
        if(column>0&& board[row][column-1] == 'O')
             CheckForSurround(board, boardVisiting, area, row, column - 1);
        if(column<board[0].Length-1&& board[row][column+1] == 'O')
             CheckForSurround(board, boardVisiting, area, row, column + 1);
    }

    public override void Run()
    {
        char[][] input =
        [
            ['X', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O'],
            ['X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'],
            ['X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X'],
            ['X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O'], 
            ['O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X'],
            ['X', 'X', 'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X'],
            ['O', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O'],
            ['O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X'], 
            ['X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O'],
            ['X', 'X', 'X', 'O', 'O', 'X', 'O', 'X', 'X', 'O']
        ];
      // Console.WriteLine(JsonSerializer.Serialize(input[0]));  
        // PrintBoard(input);
        Solve(input);
        PrintBoard(input);
    }

    void PrintBoard(char[][] board)
    {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < board.Length; i++)
        {
            sb.Append("[");
            for (int j = 0; j < board[0].Length; j++)
            {
                sb.Append($"{board[i][j]},");
            }
            sb.Append("]\n");
        }
        Console.WriteLine(sb.ToString());
    }
}