//
// Created by saeed on 12/14/25.
//

#include "LeetCode2147NumberOfWaysToDivideALongCorridor.h"

#include <iostream>
#include <vector>
using namespace std;

int LeetCode2147NumberOfWaysToDivideALongCorridor::numberOfWays(string corridor) {
    vector<int> plantsInBetween{};
    int mod = 1e9 + 7;
    long long result{};
    int plantsCount{};
    int seatCount{};
    int totalSeatCount{};
    for (const auto c: corridor) {
        if (c == 'S') {
            ++totalSeatCount;
            ++seatCount;
            if (seatCount > 2) {
                seatCount = 1;
                plantsInBetween.emplace_back(plantsCount);
                plantsCount = 0;
                continue;
            }
            continue;
        }
        if (seatCount != 2)
            continue;
        ++plantsCount;
    }
    if (totalSeatCount%2==1)
        return 0;
    int plantsInBetweenSize = plantsInBetween.size();
    if (plantsInBetweenSize == 0) {
        if (seatCount==2)
            return 1;
        return 0;
    }

    result = plantsInBetween[0] + 1;
    result %= mod;
    for (int i = 1; i < plantsInBetweenSize; ++i) {
        result *= (plantsInBetween[i] + 1);
        result %= mod;
    }
    return result;
}

void LeetCode2147NumberOfWaysToDivideALongCorridor::Run() {
    string corridor = "PPSPSP";
    cout << numberOfWays(corridor) << '\n';
}
