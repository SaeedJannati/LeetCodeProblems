//
// Created by saeed on 11/22/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODEUGLYNUMBER_H
#define LEETCODEPROBLEMSCMAKE_LEETCODEUGLYNUMBER_H
#include <cmath>
#include <iostream>
#include <limits.h>

#include "BaseProblem.h"


class LeetCodeUglyNumber : BaseProblem {
public:
    bool isUgly(int n) {
        if (n <=0) {
            return false;
        }
        while (n%2==0) {
            n>>=1;
        }
        while (n%3==0) {
            n/=3;
        }
        while (n%5==0) {
            n/=5;
        }

        return n==1;
    }

    void Run() override {
        int n = 14;
        std::cout << isUgly(n) << '\n';
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODEUGLYNUMBER_H
