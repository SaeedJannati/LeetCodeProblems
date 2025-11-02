#include "LeetCode2257CountUnguardedCellsInTheGrid.h"

#include <iostream>
#include <queue>
using namespace std;

int LeetCode2257CountUnguardedCellsInTheGrid::countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
{
    //gaurd 1
    //wall 2
    //visited 3
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (auto& wall : walls)
    {
        grid[wall[0]][wall[1]] = 2;
    }
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int newRow{};
    int newCol{};
    for (auto& guard : guards)
    {
        grid[guard[0]][guard[1]] = 1;
    }
    for (auto& guard : guards)
    {
        for (auto& direction : directions)
        {
            newRow = guard[0];
            newCol = guard[1];
            while (true)
            {
                newRow += direction.first;
                if (newRow<0 || newRow>=m)
                    break;
                newCol += direction.second;
                if (newCol<0 || newCol>=n)
                    break;
                if (grid[newRow][newCol] == 2 || grid[newRow][newCol] == 1)
                    break;
                grid[newRow][newCol] = 3;
            }
        }
    }
    int notVisitedCount{};
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (grid[i][j] == 0)
                notVisitedCount++;
        }
    }
    return notVisitedCount;
}

void LeetCode2257CountUnguardedCellsInTheGrid::Run()
{
    int m=4;
    int n=6;
    vector<vector<int>> guards={{0,0},{1,1},{2,3}};
    vector<vector<int>> walls={{0,1},{2,2},{1,4}};
    cout<<countUnguarded(m,n,guards,walls)<<'\n';
}
