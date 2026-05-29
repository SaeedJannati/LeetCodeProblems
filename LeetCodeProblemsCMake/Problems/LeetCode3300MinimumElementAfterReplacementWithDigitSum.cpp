//
// Created by saeed on 5/29/26.
//

#include "LeetCode3300MinimumElementAfterReplacementWithDigitSum.h"

#include <climits>
using namespace std;

int LeetCode3300MinimumElementAfterReplacementWithDigitSum::minElement(vector<int> &nums) {
    int minDigitSum{INT_MAX};
    int digitSum{};
    for (auto num : nums) {
        digitSum=0;
        while (num>0) {
            digitSum+=num%10;
            num/=10;
        }
        minDigitSum= min(minDigitSum, digitSum);
    }
    return minDigitSum;
}
