//
// Created by Saeed Jannati on 5/2/2026 A.
//

#include "LeetCode788RotatedDigits.h"

#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>
using namespace std;

int getFlipCount(int digit) {
    if (digit == 9)
        return 4;
    if (digit >= 6)
        return 3;
    if (digit >= 5)
        return 2;
    if (digit >= 2)
        return 1;
    return 0;
}

int getNotFlippingValid(int digit) {
    if (digit >= 8) {
        return 3;
    }
    if (digit >= 1)
        return 2;
    return 1;
}

int dp(vector<int> &digits, unordered_set<int> &validDigits, unordered_set<int> &flippingDigits,vector<vector<vector<int>>>& memo, int pos, int tight,
       int flipped) {
    if (memo[pos][tight][flipped]!=-1)
        return memo[pos][tight][flipped];
    int upperBound = tight ? digits[pos] : 9;
    if (pos == 0) {
        if (flipped==1) {
            memo[pos][tight][flipped]= getFlipCount(upperBound);
            return memo[pos][tight][flipped];
        }
        memo[pos][tight][flipped]= getNotFlippingValid(upperBound);
        return memo[pos][tight][flipped];
    }
    int result = 0;
    if (tight==1) {
        if (flipped==1) {
            if (flippingDigits.contains(digits[pos])) {
                result += dp(digits, validDigits, flippingDigits,memo, pos - 1, 1, 0);
            }
            if (validDigits.contains(digits[pos])) {
                result += dp(digits, validDigits, flippingDigits,memo, pos - 1, 1, 1);
            }
        } else {
            result += (!flippingDigits.contains(digits[pos])) && validDigits.contains(digits[pos])
                          ? dp(digits, validDigits, flippingDigits,memo, pos - 1, 1, 0)
                          : 0;
        }
        upperBound = digits[pos] - 1;
    }
    if (upperBound >= 0) {
        if (flipped==1) {
            result += getFlipCount(upperBound) * dp(digits, validDigits, flippingDigits,memo, pos - 1, 0, 0);
            result += (getFlipCount(upperBound) + getNotFlippingValid(upperBound)) * dp(
                digits, validDigits, flippingDigits, memo,pos - 1, 0, 1);
        }else {
            result += getNotFlippingValid(upperBound)* dp(digits, validDigits, flippingDigits,memo, pos - 1, 0, 0);
        }
    }
     memo[pos][tight][flipped]= result;
    return memo[pos][tight][flipped];
}

int LeetCode788RotatedDigits::rotatedDigits(int n) {
    vector<int> digits{};
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    int length = static_cast<int>(digits.size());
    vector<vector<vector<int>>> memoisation=vector<vector<vector<int>>>(length,vector<vector<int>>(2,vector<int>(2,-1)));
    unordered_set<int> flippingDigits{2, 5, 6, 9};
    unordered_set<int> validDigits{2, 5, 6, 9, 0, 1, 8};
    return dp(digits, validDigits, flippingDigits,memoisation, length - 1, 1, 1);
}

void LeetCode788RotatedDigits::Run() {
    int n = 857;
    cout << rotatedDigits(n) << endl;
}
