//
// Created by saeed on 4/11/25.
//

#include "LeetCode2843CountSymmetricIntegers.h"

#include <cmath>
using namespace std;
int getDigitCount(int n) {
    return static_cast<int>(log10(n))+1;
}
int LeetCode2843CountSymmetricIntegers::countSymmetricIntegers(int low, int high) {
    int digitCount{};
    int result{};
    int num{};
    int digitsSum{};
    int digit{};
    for (int i = low; i <= high; i++) {
        digitCount = getDigitCount(i);
        if (digitCount %2!=0) {
            i=pow(10,digitCount);
            continue;
        }
        int counter= digitCount/2;
        num = i;
        digitsSum=0;
        while (num > 0) {
            digit=num%10;
            num=num/10;
            if (counter >0) {
                digitsSum+=digit;
            }
            else {
                digitsSum-=digit;
            }
            counter--;
        }
        if (digitsSum==0) {
            result++;
        }
    }
    return result;
}
