//
// Created by saeed on 11/25/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1015SMALLESTINTEGERDIVISIBLEBYK_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1015SMALLESTINTEGERDIVISIBLEBYK_H
#include <ostream>
#include <unordered_set>
#include <iostream>
#include "BaseProblem.h"

using namespace std;

class LeetCode1015SmallestIntegerDivisibleByK: BaseProblem {
private:
    int smallestRepunitDivByK(int k) {
        if (k%2==0 || k%5==0)
            return -1;
        if (k <= 1)
            return 1;
        unordered_set<int> largerPartModsSoFar{};
        int mod{1};
        int length{1};
        while (true) {
            ++length;
            mod *= 10;
            mod = mod % k;
            if (largerPartModsSoFar.contains(mod))
                return -1;
            largerPartModsSoFar.insert(mod);
            mod += 1;
            mod = mod % k;
            if (mod == 0)
                return length;
        }
    }
public:
    void Run() override {
        int k=3;
        cout<<smallestRepunitDivByK(k)<<endl;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1015SMALLESTINTEGERDIVISIBLEBYK_H
