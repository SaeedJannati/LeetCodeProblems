#include "LeetCode54SpiralMatrix.h"

#include <iostream>

void LeetCode54SpiralMatrix::Run()
{
    std::vector<std::vector<int>> input = {{1, 2, 3,4}, { 5, 6,7,8}, {9,10,11,12}};
    auto result = spiralOrder(input);
    PrintVector(result);
}

std::vector<int> LeetCode54SpiralMatrix::spiralOrder(std::vector<std::vector<int>>& matrix)
{
    auto height = static_cast<int>(matrix.size());
    auto width = static_cast<int>(matrix[0].size());
    int currentWidth = width;
    int currentHeight = height;
    std::vector<int> result;
    result.reserve(width * height);
    int counter=0;
    while (currentWidth > 0 && currentHeight > 0)
    {
        for (int i = width - currentWidth; i < currentWidth; i++)
        {
            result.push_back(matrix[height - currentHeight][i]);
            counter++;
        }
          if(counter>=width*height)
              break;
        for (int i = height - currentHeight + 1; i < currentHeight; i++)
        {
            result.push_back(matrix[i][currentWidth - 1]);
            counter++;
        }
        if(counter>=width*height)
            break;
        for (int i = currentWidth - 2; i >= width - currentWidth; i--)
        {
            result.push_back(matrix[currentHeight - 1][i]);
            counter++;  
        }
        if(counter>=width*height)
            break;
        for (int i = currentHeight - 2; i >= height - currentHeight+1; i--)
        {
            result.push_back(matrix[i][width-currentWidth]);
            counter++;
        }
        if(counter>=width*height)
            break;
        currentWidth -= 1;
        currentHeight -= 1;
    }
    return result;
}

void LeetCode54SpiralMatrix::PrintVector(std::vector<int>& vector)
{
    for (const auto i : vector)
        std::cout << i << " ";
    std::cout << '\n';
}
