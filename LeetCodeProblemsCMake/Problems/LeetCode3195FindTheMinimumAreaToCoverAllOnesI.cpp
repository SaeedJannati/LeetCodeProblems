//
// Created by saeed on 8/24/25.
//

#include "LeetCode3195FindTheMinimumAreaToCoverAllOnesI.h"
using namespace std;

int LeetCode3195FindTheMinimumAreaToCoverAllOnesI::minimumArea(vector<vector<int> > &grid) {
    int height=static_cast<int>(grid.size());
    int width= static_cast<int>(grid[0].size());
    int maxHeight=-1;
    int maxWidth=-1;
    int minHeight=height;
    int minWidth=width;
    for (int i=0;i<height;i++) {
        for (int j=0;j<width;j++) {
            if (grid[i][j]==0) {
                continue;
            }
            maxHeight=max(maxHeight,i);
            maxWidth=max(maxWidth,j);
            minHeight=min(minHeight,i);
            minWidth=min(minWidth,j);
        }
    }
    return (maxHeight-minHeight+1)*(maxWidth-minWidth+1);
}
