#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode37SudokuSolver: BaseProblem
{
public:
    void solveSudoku(std::vector<std::vector<char>>& board);
void Run() override;
private:
    bool CanPlace(std::vector<std::vector<short>>& board,short value,short row,short column);
    bool BackTrack(std::vector<std::vector<short>>& board);
    void Convert(std::vector<std::vector<short>>& numBoard,std::vector<std::vector<char>>& board);
};
