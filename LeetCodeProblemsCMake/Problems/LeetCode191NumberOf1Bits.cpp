//
// Created by saeed on 1/23/25.
//

#include "LeetCode191NumberOf1Bits.h"



int LeetCode191NumberOf1Bits::hammingWeight(int n) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (n == 0)
            return result;
        if ((n & 1) == 1)
            result++;
        n >>= 1;
    }
    return result;
}
