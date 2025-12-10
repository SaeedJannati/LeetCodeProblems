//
// Created by saeed on 12/10/25.
//

#include "LeetCode3577CountTheNumberOfComputerUnlockingPermutations.h"
using namespace std;

int LeetCode3577CountTheNumberOfComputerUnlockingPermutations::countPermutations(vector<int> &complexity) {
    int firstElement = complexity[0];
    for (int i = 1; i < complexity.size(); i++) {
        if (complexity[i] <= firstElement) {
            return 0;
        }
    }
    int mod = 1e9 + 7;
    long long result = 1;
    for (int i = 1; i < complexity.size(); i++) {
        result *= i;
        result %= mod;
    }
    return result;
}
