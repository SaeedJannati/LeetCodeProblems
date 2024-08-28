#include "LeetCode73SetMatrixZeroes.h"

#include <iostream>
#include <unordered_set>

void LeetCode73SetMatrixZeroes::Run()
{
    std::vector<std::vector<int>> input = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(input);
    PrintMatrix(input);
}

void LeetCode73SetMatrixZeroes::setZeroes(std::vector<std::vector<int>>& matrix)
{
    std::unordered_set<int> rows;
    std::unordered_set<int> cols;
    for (int i = 0, e = static_cast<int>(matrix.size()); i < e; i++)
    {
        for (int j = 0, f = static_cast<int>(matrix[i].size()); j < f; j++)
        {
            if (matrix[i][j] != 0)
                continue;
            if (rows.find(i) == rows.end())
                rows.insert(i);
            if (cols.find(j) == cols.end())
                cols.insert(j);
        }
    }
    for (auto it = rows.begin(); it != rows.end(); ++it)
    {
        for (int& j : matrix[*it])
            j = 0;
    }
    for (auto it = cols.begin(); it != cols.end(); ++it)
        for (auto& j : matrix)
            j[*it] = 0;
}

void LeetCode73SetMatrixZeroes::PrintMatrix(const std::vector<std::vector<int>>& matrix)
{
    int size = static_cast<int>(matrix.size());
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}
