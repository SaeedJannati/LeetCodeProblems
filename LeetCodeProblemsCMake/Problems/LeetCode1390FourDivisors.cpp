//
// Created by saeed on 1/4/26.
//

#include "LeetCode1390FourDivisors.h"

#include <complex>

int LeetCode1390FourDivisors::sumFourDivisors(std::vector<int> &nums) {
    int divisorCount{},divisorSum{},totalSum{},divisorCap{},otherDivisor{};
    for (auto num:nums) {
        divisorCount=1;
        divisorSum=1;
        divisorCap= static_cast<int>( std::sqrt(num));

        for ( int i=2;i<=divisorCap;++i) {
            if (num%i!=0) {
                continue;
            }
            divisorSum+=i;
            ++divisorCount;
            otherDivisor=num/i;
            if (otherDivisor!=i) {
                divisorSum+=otherDivisor;
                ++divisorCount;
            }
            if (divisorCount>3)
                break;
        }
        if (divisorCount==3) {
            totalSum+=divisorSum+num;
        }
    }
    return totalSum;
}
