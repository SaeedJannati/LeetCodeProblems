//
// Created by saeed on 1/5/26.
//

#include "LeetCode1975MaximumMatrixSum.h"

#include <stdint.h>
using namespace std;

long long LeetCode1975MaximumMatrixSum::maxMatrixSum(vector<vector<int> > &matrix) {
    long long sum{};
    int negativeCount{};
    int minAbsolute= INT32_MAX;
    for (int i=0,e=matrix.size(); i<e; i++) {
        for (int j=0,e=matrix[0].size(); j<e; j++) {
            if (matrix[i][j] <0) {
                ++negativeCount;
                matrix[i][j]*=-1;
            }
            sum+=matrix[i][j];
            minAbsolute=min(minAbsolute, matrix[i][j]);
        }
    }
    if (negativeCount%2==1) {
        sum-= 2*minAbsolute;
    }
    return sum;
}

