#include "LeetCode1277CountSquareSubmatricesWithAllOnes.h"

#include <iostream>
using namespace std;

int LeetCode1277CountSquareSubmatricesWithAllOnes::countSquares(vector<vector<int>>& matrix)
{
    int height = static_cast<int>(matrix.size());
    int width = static_cast<int>(matrix[0].size());
    int squareCount{};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (matrix[i][j] == 0)
                continue;
            if (i > 0 & j > 0)
            {
                matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
            }

            squareCount += matrix[i][j];
        }
    }
    return squareCount;
}

void LeetCode1277CountSquareSubmatricesWithAllOnes::Run()
{
    vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    int result = countSquares(matrix);
    cout << "Count of square submatrices with all ones: " << result << endl;
}
