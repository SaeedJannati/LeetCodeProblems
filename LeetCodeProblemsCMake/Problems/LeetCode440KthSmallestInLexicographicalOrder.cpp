//
// Created by saeed on 6/12/25.
//

#include "LeetCode440KthSmallestInLexicographicalOrder.h"

#include <algorithm>
using namespace std;

int getNumsInBetween(long long first, long long second, long long n) {
    int result{};
    while (first <= n) {
        result+=min(second, n+1)-first;
        first*=10;
        second*=10;
    }
    return result;
}

int LeetCode440KthSmallestInLexicographicalOrder::findKthNumber(int n, int k) {
    int current{1};
    k--;
    int steps{};
    while (k>0) {
        steps=getNumsInBetween(current,current+1,n);
        if (steps<=k) {
            k-=steps;
            current++;
        }
        else {
            current*=10;
            k--;
        }
    }
    return current;
}
