//
// Created by saeed on 12/20/25.
//

#include "LeetCode944DeleteColumnsToMakeSorted.h"

#include <unordered_set>
using namespace std;

int LeetCode944DeleteColumnsToMakeSorted::minDeletionSize(vector<string> &strs) {
    int colsToDelete{};
    int height=static_cast<int>(strs.size());
    int width=static_cast<int>(strs[0].size());
    for (int col=0;col<width;++col){
        for (int row=1;row<height;++row){
            if (strs[row][col]<strs[row-1][col]){
                ++colsToDelete;
                break;
            }
        }
    }
    return colsToDelete;
}
