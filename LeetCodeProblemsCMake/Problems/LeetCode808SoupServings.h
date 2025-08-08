//
// Created by saeed on 8/8/25.
//

#ifndef LEETCODE808SOUPSERVINGS_H
#define LEETCODE808SOUPSERVINGS_H
#include <vector>


class LeetCode808SoupServings {
    double recurse(std::vector<std::vector<double> > &memoisation, int aRemain, int bRemain) {
        if (aRemain <= 0 && bRemain <= 0) {
            return .5;
        }
        if (aRemain <= 0) {
            return 1;
        }
        if (bRemain <= 0) {
            return 0;
        }
        if (memoisation[aRemain][bRemain] > 0.0) {
            return memoisation[aRemain][bRemain];
        }
        memoisation[aRemain][bRemain] = 0;
        memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-4, bRemain);
        memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-3, bRemain-1);
        memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-2, bRemain-2);
        memoisation[aRemain][bRemain] += recurse(memoisation, aRemain-1, bRemain-3);
        memoisation[aRemain][bRemain] *=.25;
        return memoisation[aRemain][bRemain];
    }

    double soupServings(int n) {
        if (n > 4300)
            return 1;
        int m = (n + 24) / 25;
        std::vector<std::vector<double> > memoisation(m+1, std::vector<double>(m+1, -1.0));
        return recurse(memoisation, m, m);
    }
};


#endif //LEETCODE808SOUPSERVINGS_H
