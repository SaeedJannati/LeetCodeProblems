//
// Created by saeed on 1/5/25.
//

#include "LeetCode60PermutationSequence.h"

#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

std::string LeetCode60PermutationSequence::getPermutation(int n, int k) {
    int permutations = CalcFactorial(n);
    std::string result;
    std::vector<int> possibiliteis(n);
    std::iota(possibiliteis.begin(), possibiliteis.end(), 1);

    int index = 0;
    k--;
    while (possibiliteis.size() > 0) {
        if (k != 0) {
            index = k * n / permutations;
            k = k % (permutations / n);
        } else {
            index = 0;
        }
        result.append(std::to_string(possibiliteis[index]));
        possibiliteis.erase(possibiliteis.begin() + index);
        permutations /= n;
        n--;
    }
    return result;
}

int LeetCode60PermutationSequence::CalcFactorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

void LeetCode60PermutationSequence::Run() {
    int n = 4;
    int k = 9;
    std::cout << LeetCode60PermutationSequence::getPermutation(n, k) << std::endl;
}
