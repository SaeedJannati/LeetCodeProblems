//
// Created by saeed on 5/4/25.
//

#include "LeetCode1128NumberOfEquivalentDominoPairs.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int LeetCode1128NumberOfEquivalentDominoPairs::numEquivDominoPairs(vector<vector<int> > &dominoes) {
    unordered_map<int, unordered_map<int,int> > dominoMap{};
    dominoMap.reserve(9);
    int larger{};
    int smaller{};
    for (auto &domino: dominoes) {
        if (domino[0]>domino[1]) {
            larger = domino[0];
            smaller = domino[1];
        }
        else {
            larger = domino[1];
            smaller = domino[0];
        }
        if (!dominoMap.contains(larger)) {
            dominoMap[larger] = {};
        }
        if (!dominoMap[larger].contains(smaller)) {
            dominoMap[larger][smaller] = 0;
        }
        dominoMap[larger][smaller]++;
    }
    int result{};
    int size{};
    for (auto &pair: dominoMap) {
        for (auto &count: pair.second) {
            size=count.second;
            if (size > 1)
                result += size*(size-1)/2;
        }
    }
    return result;
}

void LeetCode1128NumberOfEquivalentDominoPairs::Run() {
    vector<vector<int> > dominoes = {{1,1},{2,2},{1,1},{1,2},{1,2},{1,1}};
    cout << numEquivDominoPairs(dominoes) << '\n';
}
