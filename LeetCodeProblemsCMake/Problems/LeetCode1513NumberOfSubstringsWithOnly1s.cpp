//
// Created by saeed on 11/16/25.
//

#include "LeetCode1513NumberOfSubstringsWithOnly1s.h"
using namespace std;

int LeetCode1513NumberOfSubstringsWithOnly1s::numSub(string s) {
    long result{};
    long consecutiveOnesCount{};
    long mod=1e9+7;
    long delta{};
    for (auto c:s) {
        if (c=='1') {
            consecutiveOnesCount++;
            continue;
        }
        if (consecutiveOnesCount>0) {
            delta=consecutiveOnesCount;
            delta*=(consecutiveOnesCount+1);
            delta/=2;
            delta%=mod;
            result+=delta;
            result%=mod;
            consecutiveOnesCount=0;
        }

    }
    if (consecutiveOnesCount>0) {
        delta=consecutiveOnesCount;
        delta*=(consecutiveOnesCount+1);
        delta/=2;
        delta%=mod;
        result+=delta;
        result%=mod;
    }
    return result;
}
