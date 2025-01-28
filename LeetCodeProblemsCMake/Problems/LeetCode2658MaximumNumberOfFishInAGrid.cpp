//
// Created by saeed on 1/28/25.
//

#include "LeetCode2658MaximumNumberOfFishInAGrid.h"
void Dfs(std::vector<std::vector<int>> &grid,const int height,const int width,std::vector<std::pair<int,int>>& directions, int row,int col,int& fishInSection) {
    if (grid[row][col]==0)
        return;
    if (grid[row][col]==-1)
        return;
    fishInSection+=grid[row][col];
    grid[row][col]=-1;
    for (auto& direction:directions) {
        int newRow=row+direction.first;
        int newCol=col+direction.second;
        if (newRow<0 || newRow>=height || newCol<0 || newCol>=width)
            continue;
        Dfs(grid,height,width,directions,newRow,newCol,fishInSection);
    }
}
int LeetCode2658MaximumNumberOfFishInAGrid::findMaxFish(std::vector<std::vector<int>> &grid) {
    int height = static_cast<int>( grid.size());
    int width = static_cast<int>( grid[0].size());
    std::vector<std::pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    int maxFishInSection = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int fishInSection = 0;
            Dfs(grid,height,width,directions,i,j,fishInSection);
            if (fishInSection > maxFishInSection)
                maxFishInSection = fishInSection;
        }
    }
    return maxFishInSection;
}
