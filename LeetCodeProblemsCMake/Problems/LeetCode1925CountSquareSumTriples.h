//
// Created by saeed on 12/8/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1925COUNTSQUARESUMTRIPLES_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1925COUNTSQUARESUMTRIPLES_H
#include <cmath>


class LeetCode1925CountSquareSumTriples {
    int countTriples(int n) {
        int result{};
        for (int i=1;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                int sumOfSquares=i*i+j*j;
                int k= std::sqrt(sumOfSquares);
                if (k<=n && k*k==sumOfSquares)        {
                    result+=2;
                }
            }
        }
        return result;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1925COUNTSQUARESUMTRIPLES_H