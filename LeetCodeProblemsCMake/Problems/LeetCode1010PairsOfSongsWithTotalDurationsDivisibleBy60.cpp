//
// Created by Saeed Jannati on 5/5/2026 A.
//

#include "LeetCode1010PairsOfSongsWithTotalDurationsDivisibleBy60.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

int LeetCode1010PairsOfSongsWithTotalDurationsDivisibleBy60::numPairsDivisibleBy60(vector<int> &time) {
    unordered_map<int,int> modMap{};
    for (auto num:time) {
        if (!modMap.contains(num%60)) {
            modMap[num%60] ={};
        }
        ++modMap[num%60];
    }
    int result{};
    for (auto pair:modMap) {
        if (pair.first>29)
            continue;
        if (!modMap.contains(60-pair.first)) {
            continue;
        }
        result+=pair.second*modMap[60-pair.first];
    }
    long long delta{};
    if (modMap.contains(0)) {
        delta=modMap[0];
        delta*=modMap[0]-1;
        delta>>=1;
        result+=delta;
    }
    if (modMap.contains(30)) {
        delta=modMap[30];
        delta*=modMap[30]-1;
        delta>>=1;
        result+=delta;
    }
    return result;
}

void LeetCode1010PairsOfSongsWithTotalDurationsDivisibleBy60::Run() {
    vector<int> times{30,20,150,100,40};
    cout << numPairsDivisibleBy60(times) << endl;
}
