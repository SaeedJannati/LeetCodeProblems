namespace LeetCodeProblems.Problems;

public class LeetCode36ValidSudoku: BaseProblemClass
{
    public bool IsValidSudoku(char[][] board)
    {
        HashSet<char> numsInSet = new(9);
        HashSet<char> numsInSecondSet = new(9);
        for (int i = 0; i < 9; i++)
        {
             numsInSet = new(9);
             numsInSecondSet = new(9);
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (!numsInSet.Add(board[i][j]))
                        return false;
                }

                if (board[j][i] != '.')
                {
                    if (!numsInSecondSet.Add(board[j][i]))
                        return false;
                }
            }
        }

        int[] squaresMiddle = {1, 4, 7};
        foreach (int first in squaresMiddle)
        {
            foreach (int second in squaresMiddle)
            {
                numsInSet = new(9);
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (board[first+i][second+j] != '.')
                        {
                            if (!numsInSet.Add(board[first+i][second+j]))
                                return false;
                        }  
                    }
                    
                }
            }
        }

        return true;
    }

    public override void Run()
    {
        char[][] board =
        [
            ['5', '3', '.', '.', '7', '.', '.', '.', '.'], ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            ['.', '9', '8', '.', '.', '.', '.', '6', '.'], ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            ['4', '.', '.', '8', '.', '3', '.', '.', '1'], ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            ['.', '6', '.', '.', '.', '.', '2', '8', '.'], ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            ['.', '.', '.', '.', '8', '.', '.', '7', '9']
        ];
        Console.WriteLine(IsValidSudoku(board));
    }
}