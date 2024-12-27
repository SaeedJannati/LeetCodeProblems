#include "LeetCode37SudokuSolver.h"

void LeetCode37SudokuSolver::solveSudoku(std::vector<std::vector<char>>& board)
{
    std::vector<std::vector<short>> sudoku(9, std::vector<short>(9, 0));
    short zeroCounts = 0;
    char digit = '0';
    for (short i = 0; i < 9; i++)
    {
        for (short j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                zeroCounts++;
                continue;
            }
            sudoku[i][j] = board[i][j] - digit;
        }
    }
    BackTrack(sudoku);
    Convert(sudoku, board);
}


bool LeetCode37SudokuSolver::CanPlace(std::vector<std::vector<short>>& board, short value, short row, short column)
{
    for (short i = 0; i < 9; i++)
    {
        if (board[row][i] == value)
            return false;
        if (board[i][column] == value)
            return false;
    }
    short baseRow = row / 3 * 3;
    short baseColumn = column / 3 * 3;
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (board[baseRow + i][baseColumn + j] == value)
                return false;
        }
    }
    return true;
}

bool LeetCode37SudokuSolver::BackTrack(std::vector<std::vector<short>>& board)
{
    for (short row = 0; row < 9; row++)
    {
        for (short column = 0; column < 9; column++)
        {
            if (board[row][column] != 0)
                continue;
            for (short k = 1; k < 10; k++)
            {
                if (!CanPlace(board, k, row, column))
                    continue;
                board[row][column] = k;
                if (BackTrack(board))
                {
                    return true;
                }
                board[row][column] = 0;
            }
            return false;
        }
    }
    return true;
}

void LeetCode37SudokuSolver::Convert(std::vector<std::vector<short>>& numBoard, std::vector<std::vector<char>>& board)
{
    for (short i = 0; i < 9; i++)
    {
        for (short j = 0; j < 9; j++)
        {
            board[i][j] = '0' + numBoard[i][j];
        }
    }
}


void LeetCode37SudokuSolver::Run()
{
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board);
}
