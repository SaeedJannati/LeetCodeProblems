//
// Created by saeed on 12/2/25.
//

#include "LeetCode3623CountNumberOfTrapezoidsI.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int LeetCode3623CountNumberOfTrapezoidsI::countTrapezoids(vector<vector<int> > &points) {
    unordered_map<int, unordered_set<int> > yMap{};
    for (auto &point: points) {
        yMap[point[1]].insert(point[0]);
    }
    long long delta{};
    const long long mod = 1e9 + 7;
    int ySetSize{};
    long long totalSum{};
    long long totalSquared{};
    for (auto &ySet: yMap) {
        ySetSize = ySet.second.size();
        if (ySetSize < 2)
            continue;
        delta = ySetSize;
        delta *= ySetSize - 1;
        delta >>= 1;
        delta %= mod;
        totalSum += delta;
        totalSum %= mod;
        delta *= delta;
        delta %= mod;
        totalSquared += delta;
        totalSquared %= mod;
    }
    totalSum *= totalSum;
    totalSum %= mod;


    long long result = (totalSum-totalSquared );
    result = (result + mod) % mod;



    long long inv2 = (mod + 1) / 2;   // inverse of 2
    result = (result * inv2) % mod;
    return result;
}

void LeetCode3623CountNumberOfTrapezoidsI::Run() {
 vector<vector<int>> points= {{1,0},{2,0},{3,0},{2,2},{3,2}};
    cout << countTrapezoids(points)<<'\n';
}
