//
// Created by saeed on 12/1/25.
//

#include "LeetCode2141MaximumRunningTimeOfNComputers.h"

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

long long LeetCode2141MaximumRunningTimeOfNComputers::maxRunTime(int n, vector<int> &batteries) {
    long long totalPower = accumulate(batteries.begin(), batteries.end(), 0LL);
    long long maxTarget = totalPower / n;
    long long minTarget = 1;
    long long target{};
    long long midTarget{};
    long long power{};
    long long desiredPower{};
    while (minTarget <= maxTarget) {
        midTarget = (minTarget + maxTarget) >> 1;
        power = 0;
        for (auto battery: batteries) {
            power += min(static_cast<long long> (battery), midTarget);
        }
        desiredPower = n;
        desiredPower *= midTarget;
        if (power >= desiredPower) {
            target = max(midTarget, target);
            minTarget = midTarget + 1;
            continue;
        }
        maxTarget = midTarget - 1;
    }
    return target;
}

void LeetCode2141MaximumRunningTimeOfNComputers::Run() {
    std::vector<int> batteries = {5, 5, 4};
    int n = 2;
    cout << maxRunTime(n, batteries) << '\n';
}
