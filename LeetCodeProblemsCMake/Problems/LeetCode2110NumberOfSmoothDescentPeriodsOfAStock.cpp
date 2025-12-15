//
// Created by saeed on 12/15/25.
//

#include "LeetCode2110NumberOfSmoothDescentPeriodsOfAStock.h"

#include <iostream>
using namespace std;

long long LeetCode2110NumberOfSmoothDescentPeriodsOfAStock::getDescentPeriods(vector<int> &prices) {
    int length= static_cast<int>(prices.size());
    vector<int> dp(length,1);
    for (int i{1}; i<length; ++i) {
        dp[i]=prices[i-1]-prices[i]==1?dp[i-1]+1:1;
    }
    long long result{};
    long long delta{};
    for (int i{length-1}; i>=0;) {
        if (dp[i]>1) {
            delta=dp[i]+1;
            delta*=delta-1;
            delta>>=1;
            result+= delta;
            i-=dp[i];
            continue;
        }
        result+=dp[i];
        --i;
    }
    return result;
}

void LeetCode2110NumberOfSmoothDescentPeriodsOfAStock::Run() {
    vector<int> nums={12,11,10,9,8,7,6,5,4,3,4,3,10,9,8,7};
    cout<<getDescentPeriods(nums)<<'\n';
}
