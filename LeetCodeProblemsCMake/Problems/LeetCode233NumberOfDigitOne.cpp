//
// Created by Saeed Jannati on 5/3/2026 A.
//

#include "LeetCode233NumberOfDigitOne.h"

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int dp(vector<int> &digits, vector<vector<vector<int> > > &memo, int pos, int tight, int onesPlaced) {
    if (onesPlaced < 0)
        return 0;
    if (onesPlaced > pos + 1)
        return 0;
    if (memo[pos][tight][onesPlaced] != -1)
        return memo[pos][tight][onesPlaced];
    int upperBound = tight == 1 ? digits[pos] : 9;
    if (pos == 0) {
        if (onesPlaced > 1) {
            memo[pos][tight][onesPlaced] = 0;
            return memo[pos][tight][onesPlaced];
        }
        if (onesPlaced == 1) {
            memo[pos][tight][onesPlaced] = upperBound > 0 ? 1 : 0;
            return memo[pos][tight][onesPlaced];
        }
        memo[pos][tight][onesPlaced] = upperBound == 0 ? upperBound + 1 : upperBound;
        return memo[pos][tight][onesPlaced];
    }
    int result{};
    if (tight == 1) {
        if (digits[pos] == 1) {
            result += dp(digits, memo, pos - 1, 1, onesPlaced - 1);
        } else {
            result += dp(digits, memo, pos - 1, 1, onesPlaced);
        }
        upperBound--;
    }

    if (upperBound < 0) {
        memo[pos][tight][onesPlaced] = result;
        return memo[pos][tight][onesPlaced];
    }

    int delta = upperBound == 0 ? upperBound + 1 : upperBound;
    result += delta * dp(digits, memo, pos - 1, 0, onesPlaced);
    if (upperBound > 0)
        result += dp(digits, memo, pos - 1, 0, onesPlaced - 1);


    memo[pos][tight][onesPlaced] = result;
    return memo[pos][tight][onesPlaced];
}

int LeetCode233NumberOfDigitOne::countDigitOne(int n) {
    if (n == 0) {
        return 0;
    }
    vector<int> digits{};
    int num{n};
    while (num != 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    int result{};
    int length = static_cast<int>(digits.size());
    vector<vector<vector<int> > > memo(length, vector<vector<int> >(2, vector<int>(length + 1, -1)));
    for (int i = 1; i <= length; i++) {
        result += i * dp(digits,memo, length - 1, true, i);
    }
    return result;
}

void LeetCode233NumberOfDigitOne::Run() {
    int n = 999;
    cout << countDigitOne(n) << endl;
}
