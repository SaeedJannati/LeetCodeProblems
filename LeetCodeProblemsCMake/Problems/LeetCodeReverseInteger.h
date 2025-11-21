//
// Created by saeed on 11/21/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODEREVERSEINTEGER_H
#define LEETCODEPROBLEMSCMAKE_LEETCODEREVERSEINTEGER_H
#include <algorithm>
#include <stdint.h>
#include <string>
#include <vector>

using namespace std;

class LeetCodeReverseInteger {
    int reverse(int x) {
        bool isPos = x >= 0;

        if (x == INT32_MIN)
            return 0;

        if (isPos == false)
            x = -x;

        vector<int> digits{};
        while (x != 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
        int num = 0;
        for (int d: digits) {
            if (num > INT32_MAX / 10)
                return 0;
            if (num == INT32_MAX / 10 && d > INT32_MAX % 10)
                return 0;

            num = num * 10 + d;
        }

        return isPos ? num : -num;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODEREVERSEINTEGER_H
