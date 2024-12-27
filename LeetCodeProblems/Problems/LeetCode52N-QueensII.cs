using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode52N_QueensII : BaseProblemClass
{
    private int solutionCount = 0;

    public override void Run()
    {
        int n = 8;
        var outPut = TotalNQueens(n);
        Console.WriteLine(outPut);
    }

    public int TotalNQueens(int n)
    {
        List<List<List<int>>> boards = [];
        for (int i = 0; i < n; i++)
        {
            AddQueen(boards, n,i);
        }
        return boards.Count;
    }
    private void AddQueen(List<List<List<int>>> boards, int n,int rowNum)
    {
        if (boards.Count == 0)
        {
            for (int i = 0; i < n; i++)
            {
               
                    var board = Enumerable.Range(0, n)
                        .Select(_ => new List<int>(new int[n]))
                        .ToList();
                    PlaceAt(0,i,board);
                    boards.Add(board);
                
            }

            return;
        }

        bool placedAny;
        for (int i = boards.Count - 1; i >= 0; i--)
        {
            placedAny = false;
            List<List<int>> temp =  boards[i].Select(row => new List<int>(row)).ToList();
           
                for (int k = 0; k < n; k++)
                {
                    List<List<int>> temp1 = temp.Select(row => new List<int>(row)).ToList();
                    if (PlaceAt(rowNum, k, temp1))
                    {
                        if (!placedAny)
                        {
                            boards[i] = temp1.Select(row => new List<int>(row)).ToList();
                            placedAny = true;
                            continue;
                        }

                        boards.Add(temp1.Select(row => new List<int>(row)).ToList());
                    }
             
            }

            if (!placedAny)
                boards.RemoveAt(i);
        }
    }

    private bool PlaceAt(int row, int col, List<List<int>> board)
    {
        if (board[row][col] != 0)
            return false;
        int size = board.Count;
        var temp = new List<(int row, int col)>(3 * size);
        for (int i = 0; i < board.Count; i++)
        {
            if (board[i][col] == 1)
                return false;
            temp.Add((i, col));
            if (board[row][i] == 1)
                return false;
            temp.Add((row, i));
            if (row - i >= 0 && col - i >= 0)
            {
                if (board[row - i][col - i] == 1)
                    return false;
                temp.Add((row - i, col - i));
            }

            if (row + i < board.Count && col + i < board.Count)
            {
                if (board[row + i][col + i] == 1)
                    return false;
                temp.Add((row + i, col + i));
            }
            if (row - i >= 0 && col + i < board.Count)
            {
                if (board[row - i][col + i] == 1)
                    return false;
                temp.Add((row - i, col + i));
            }

            if (row + i < board.Count && col - i >= 0)
            {
                if (board[row + i][col - i] == 1)
                    return false;
                temp.Add((row + i, col - i));
            }
        }

        temp.ForEach(i => board[i.row][i.col] = -1);
        board[row][col] = 1;
        return true;
    }
}