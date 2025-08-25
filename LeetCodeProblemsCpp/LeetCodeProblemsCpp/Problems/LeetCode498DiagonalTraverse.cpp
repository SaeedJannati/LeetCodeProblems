#include "LeetCode498DiagonalTraverse.h"

#include "Auxilaries.h"
using namespace std;

vector<int> LeetCode498DiagonalTraverse::findDiagonalOrder(vector<vector<int>>& mat)
{
    int heigth = static_cast<int>(mat.size());
    int width = static_cast<int>(mat[0].size());
    pair<int, int> startPos = {0, 0};
    int slope = 1;
    vector<int> result;
    result.reserve(heigth * width);
    pair<int, int> currentPos;

    while (result.size() < heigth * width)
    {
        currentPos = make_pair(startPos.first, startPos.second);
        if (slope == 1)
        {
            while (currentPos.first>=0&&currentPos.second<width)
            {
                result.push_back(mat[currentPos.first][currentPos.second]);
                currentPos.first--;
                currentPos.second++;
            }
            currentPos.second --;
            currentPos.first++;
            if (currentPos.second<width-1)
            {
                startPos.second=currentPos.second+1;
                startPos.first = currentPos.first;
            }
            else
            {
                startPos.first=currentPos.first+1;
                startPos.second = currentPos.second;
            }
        }
        else
        {
            while (currentPos.second>=0&&currentPos.first<heigth)
            {
                result.push_back(mat[currentPos.first][currentPos.second]);
                currentPos.first++;
                currentPos.second--;
            }
            currentPos.first--;
            currentPos.second ++;
            if (currentPos.first<heigth-1)
            {
                startPos.first=currentPos.first+1;
                startPos.second = currentPos.second;
            }
            else
            {
                startPos.second=currentPos.second+1;
                startPos.first = currentPos.first;
            }
        }
        slope *= -1;
    }
    return result;
}

void LeetCode498DiagonalTraverse::Run()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = findDiagonalOrder(mat);
    Auxilaries::PrintVector(result);
}
