//
// Created by saeed on 9/29/25.
//

#include "LeetCode1039MinimumScoreTriangulationOfPolygon.h"

#include <stdint.h>
using namespace std;

int findOptimalSolution(vector<int> &values,vector<vector<int>> & memoisation, int start, int end) {
    if (memoisation[start][end]!=-1)
        return memoisation[start][end];
    if (end - start < 2) {
        memoisation[start][end] = 0;
        return memoisation[start][end];
    }
    if (end - start == 2) {
        memoisation[start][end] =  values[start] * values[start + 1] * values[end];
        return memoisation[start][end];
    }

    int minScore{INT32_MAX};
    int currentScore{};
    for (int i = start + 1; i < end; i++) {
        currentScore = values[start] * values[end] * values[i];
        currentScore += findOptimalSolution(values, memoisation,start, i);
        currentScore += findOptimalSolution(values,memoisation, i, end);
        minScore = min(minScore, currentScore);
    }
    memoisation[start][end] = minScore;
    return     memoisation[start][end] ;
}

int LeetCode1039MinimumScoreTriangulationOfPolygon::minScoreTriangulation(vector<int> &values) {
    int length = values.size();
    vector<vector<int>> memoisation(length, vector<int>(length, -1));
    return findOptimalSolution(values,memoisation, 0, values.size() - 1);
}
