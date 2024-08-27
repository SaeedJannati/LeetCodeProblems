#include "LeetCode48RotateImage.h"

#include <iostream>

void LeetCode48RotateImage::Run()
{
    std::vector<std::vector<int>> input =
        // {{1,2,3},
        // {4,5,6},
        // {7,8,9}};
        {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    rotate(input);
    
    PrintMatrix(input);
}

void LeetCode48RotateImage::rotate(std::vector<std::vector<int>>& matrix)
{
    int size = matrix.size();
    int halfSize = size / 2;
    int myInt = size % 2 == 1 ? 2 * halfSize : 2 * halfSize - 1;

    int newFirst(0);
    int newSecond(0);
    int newThird(0);
    int newFourth(0);
    for (int i = 0, e = size % 2 == 0 ? halfSize : halfSize + 1; i < e; i++)
        for (int j = 0, f = halfSize; j < f; j++)
        {
            newFirst = matrix[myInt - j][i];
            newSecond = matrix[i][j];
            newThird = matrix[j][myInt - i];
            newFourth = matrix[myInt - i][myInt - j];
            matrix[i][j] = newFirst;
            matrix[j][myInt - i] = newSecond;
            matrix[myInt - i][myInt - j] = newThird;
            matrix[myInt - j][i] = newFourth;
        }

}

void LeetCode48RotateImage::PrintMatrix(std::vector<std::vector<int>>& matrix)
{
    int size = matrix.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}
