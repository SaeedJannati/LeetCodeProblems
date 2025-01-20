//
// Created by saeed on 1/20/25.
//

#include "LeetCode2661FirstCompletelyPaintedRowOrColumn.h"

#include <unordered_map>

int LeetCode2661FirstCompletelyPaintedRowOrColumn::firstCompleteIndex(std::vector<int> &arr,
                                                                      std::vector<std::vector<int>> &mat) {
    int height = mat.size();
    int width = mat[0].size();
    std::unordered_map<int,std::pair<int,int>> map;
    std::vector<int> rowNotVisitedCount(height,width);
    std::vector<int> colNotVisitedCount(width,height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[mat[i][j]]= {i,j};
        }
    }
    int row = 0;
    int col = 0;
    for (int i=0,e=arr.size();i<e;i++) {
        auto coords=map[arr[i]];
        row=coords.first;
        col=coords.second;
        rowNotVisitedCount[row]--;
        if (rowNotVisitedCount[row] == 0) {
            return i;
        }
        colNotVisitedCount[col]--;
        if (colNotVisitedCount[col] == 0) {
            return i;
        }
    }
    return arr.size()-1;


}
