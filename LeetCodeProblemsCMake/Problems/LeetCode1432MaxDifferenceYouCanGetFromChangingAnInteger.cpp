//
// Created by saeed on 10/6/25.
//

#include "LeetCode1432MaxDifferenceYouCanGetFromChangingAnInteger.h"

#include <iostream>
#include <vector>

using namespace std;

vector<int> getDigits(int nums) {
    vector<int> digits{};
    while (nums != 0) {
        digits.push_back(nums % 10);
        nums /= 10;
    }
    return digits;
}

int LeetCode1432MaxDifferenceYouCanGetFromChangingAnInteger::maxDiff(int num) {
    auto digits = getDigits(num);
    int digitToChange{-1};
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != 9) {
            digitToChange = digits[i];
            break;
        }
    }
    int maxNum{num};
    if (digitToChange != -1) {
        maxNum=0;
        for (int i =  digits.size()-1; i >=0; i--) {
            maxNum *= 10;
            maxNum += (digits[i] == digitToChange) ? 9 : digits[i];
        }
    }
    digitToChange = -1;
    int digitToReplace{};
    int firstDigit{digits[digits.size() - 1]};
    if (firstDigit != 1) {
        digitToChange = firstDigit;
        digitToReplace = 1;
    } else {
        for (int i = digits.size() - 2; i >= 0; --i) {
            if (digits[i] != 0) {
                if (digits[i] == firstDigit)
                    continue;
                digitToChange = digits[i];
                digitToReplace = 0;
                break;
            }
        }
    }
    int minNum{num};
    if (digitToChange != -1) {
        minNum=0;
        for (int i =  digits.size()-1; i >=0; i--) {
            minNum *= 10;
            minNum += (digits[i] == digitToChange) ? digitToReplace : digits[i];
        }
    }
    return maxNum - minNum;
}

void LeetCode1432MaxDifferenceYouCanGetFromChangingAnInteger::Run() {
    int num =123456;
    cout << maxDiff(num) << endl;
}
