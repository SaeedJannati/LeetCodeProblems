//
// Created by saeed on 5/27/25.
//

#include "LeetCode2894DivisibleAndNondivisibleSumsDifference.h"

int LeetCode2894DivisibleAndNondivisibleSumsDifference::differenceOfSums(int n, int m) {
    long long sum=(1+n);
    sum*=n;
    sum/=2;
    long long divisable=m+((n/m)*m);
    divisable*= (n/m);
    divisable/=2;
    return sum-2*divisable;
}
