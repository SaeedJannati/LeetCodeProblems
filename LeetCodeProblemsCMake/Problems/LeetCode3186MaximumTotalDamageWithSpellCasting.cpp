//
// Created by saeed on 10/11/25.
//

#include "LeetCode3186MaximumTotalDamageWithSpellCasting.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

long long LeetCode3186MaximumTotalDamageWithSpellCasting::maximumTotalDamage(vector<int> &power) {
    unordered_map<int, int> powersMap{};
    ranges::sort(power);
    int length = static_cast<int>(power.size());
    int uniquePointer{};
    int temp{};
    for (int i = 0; i < length; i++) {
        temp = power[i];
        if (!powersMap.contains(power[i])) {
            std::swap(power[i], power[uniquePointer]);
            ++uniquePointer;
        }
        ++powersMap[temp];
    }
    vector<long long> dp(uniquePointer, 0);
    dp[0] = static_cast<long long>( power[0])*static_cast<long long>( powersMap[power[0]]) ;
    int prev{};
    int beforePrev{};
    int firstCatchable{};
    int delta{};
    long long maxCast{dp[0]};
    for (int i = 1; i < uniquePointer; i++) {
        delta = power[i] - power[i - 1];
        prev = -1;
        beforePrev = -1;
        firstCatchable = -1;
        if (delta == 1) {
            prev = i - 1;
        }
        if (delta == 2) {
            beforePrev = i - 1;
        }
        if (delta > 2) {
            firstCatchable = i - 1;
        }
        if (i > 1) {
            delta = power[i] - power[i - 2];
            if (delta == 2) {
                beforePrev = i - 2;
            }
            if (delta > 2 && firstCatchable == -1) {
                firstCatchable = i - 2;
            }
        }
        if (i > 2) {
            delta = power[i] - power[i - 3];
            if (delta > 2 && firstCatchable == -1) {
                firstCatchable = i - 3;
            }
        }
        dp[i] = power[i]*powersMap[power[i]];
        if (prev != -1) {
            dp[i] =max( dp[prev],dp[i]);
        }
        if (beforePrev != -1) {
            dp[i] = max(dp[i], dp[beforePrev]);
        }
        if (firstCatchable != -1) {
            long long temp=dp[firstCatchable];
            temp+=static_cast<long long>(power[i])*static_cast<long long>(powersMap[power[i]]);
            dp[i]=max(dp[i],temp);
        }
        maxCast=max(dp[i],maxCast);
    }
    return maxCast;
}

void LeetCode3186MaximumTotalDamageWithSpellCasting::Run() {
    vector<int> powers{3,3,1,2,3,3,1,2,1};
    cout << maximumTotalDamage(powers) << endl;
}
