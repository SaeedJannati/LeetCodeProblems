//
// Created by Saeed Jannati on 4/28/2026 A.
//

#include "LeetCode1680ConcatenationOfConsecutiveBinaryNumbers.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;



int LeetCode1680ConcatenationOfConsecutiveBinaryNumbers::concatenatedBinary(int n) {
    long long result{};
    int bitLength{};
    int mod = 1e9+7;
    for (int i = 1; i <= n; ++i) {
        if ((i&(i-1))==0) {
            ++bitLength;
        }
        result = (result << bitLength) | i;
        result %= mod;
    }
    return result;
}

void LeetCode1680ConcatenationOfConsecutiveBinaryNumbers::Run() {
    int n = 3;
    cout << concatenatedBinary(n) << endl;
}
