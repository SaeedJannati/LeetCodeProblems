//
// Created by saeed on 12/21/25.
//

#include "LeetCode955DeleteColumnsToMakeSortedII.h"
using namespace std;

int LeetCode955DeleteColumnsToMakeSortedII::minDeletionSize(vector<string> &strs) {
    int height=static_cast<int>(strs.size());
    int width=static_cast<int>(strs[0].size());
    int colsToDelete=0;
    vector<bool> rowsToCheck(height-1,true);
    vector<bool> newRowsToCheck(height-1,true);

    bool colDeleted=false;

    for (int col = 0; col < width; ++col) {
        colDeleted = false;
        newRowsToCheck = rowsToCheck;

        for (int row = 0; row < height - 1; ++row) {
            if (!rowsToCheck[row])
                continue;

            if (strs[row][col] > strs[row + 1][col]) {
                ++colsToDelete;
                colDeleted = true;
                break;
            }

            if (strs[row][col] < strs[row + 1][col]) {
                newRowsToCheck[row] = false;
            }
        }

        if (!colDeleted) {
            rowsToCheck = newRowsToCheck;
        }
    }
    return colsToDelete;
}
