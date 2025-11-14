//
// Created by saeed on 11/14/25.
//

#include "LeetCode2536IncrementSubmatricesByOne.h"
using namespace std;

vector<vector<int> > LeetCode2536IncrementSubmatricesByOne::rangeAddQueries(int n,
                                                                            vector<vector<int> > &queries) {
    vector<vector<int> > result(n, vector<int>(n, 0));
    int startRow{};
    int endRow{};
    int endCol{};
    for (auto &query: queries) {
        startRow = query[0];
        endRow = query[2];
        endCol = query[3] < n - 1 ? query[3]+1 : -1;
        for (int i = startRow; i <= endRow; i++) {
            ++result[i][query[1]];
            if (endCol!=-1) {
                --result[i][endCol];
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=1;j<n;j++) {
                result[i][j]+=result[i][j-1];
        }
    }
    return result;
}
