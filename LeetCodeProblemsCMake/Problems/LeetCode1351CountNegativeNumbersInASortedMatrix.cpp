//
// Created by saeed on 12/28/25.
//

#include "LeetCode1351CountNegativeNumbersInASortedMatrix.h"
using  namespace std;
int LeetCode1351CountNegativeNumbersInASortedMatrix::countNegatives( vector< vector<int>> &grid) {
    int height{static_cast<int>(grid.size())};
    int width{static_cast<int>(grid[0].size())};
    int negativeCount{0};
    int begin{0};
    int end{width-1};
    int mid{};
    int currentEnd{end};
    int result{0};
    for (int i=0;i<height;++i) {
        end=currentEnd;
        begin=0;
        result=end+1;
        while (begin<=end) {
            mid=(begin+end)>>1;
            if (grid[i][mid]<0) {
                result=min(result,mid);
                end=mid-1;
                continue;
            }
            begin=mid+1;
        }
        if (result==currentEnd+1) {
            continue;
        }
        negativeCount+= (currentEnd-result+1)*(height-i);
        currentEnd=result-1;
    }
    return negativeCount;
}
