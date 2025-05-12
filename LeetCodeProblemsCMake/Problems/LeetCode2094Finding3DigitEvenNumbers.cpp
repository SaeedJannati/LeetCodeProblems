//
// Created by saeed on 5/12/25.
//

#include "LeetCode2094Finding3DigitEvenNumbers.h"

#include <algorithm>
#include <unordered_set>
#include <bits/ranges_algo.h>

#include "../Auxilary/Auxilaries.h"
using namespace std;

vector<int> LeetCode2094Finding3DigitEvenNumbers::findEvenNumbers(vector<int> &digits) {
    int digitFrequency[10]={0};
    for (auto d: digits) {
        digitFrequency[d]++;
    }
    vector<int> result{};
    int hundreds = 1;
    int tens = 1;
    int requiredFreq{};
    for (int i = 1; i < 10; i++) {
        if (digitFrequency[i] == 0)
            continue;
        hundreds =i;
        for (int j = 0; j < 10; j++) {
            if (digitFrequency[j] == 0)
                continue;
            requiredFreq=1;
            if (j==hundreds) {
                requiredFreq++;
            }
            if (digitFrequency[j]<requiredFreq)
                continue;
            tens=j;
            for (int k=0;k<10;k+=2) {
                if (digitFrequency[k]==0)
                    continue;
                requiredFreq=1;
                if (k==hundreds)
                    requiredFreq++;
                if (k==tens)
                    requiredFreq++;
                if (digitFrequency[k]<requiredFreq)
                    continue;
                result.push_back(i*100+j*10+k);
            }

        }
    }
    return result;
}

void LeetCode2094Finding3DigitEvenNumbers::Run() {
    vector<int> digits{2,1,3,0};
    Auxilaries::PrintVector(findEvenNumbers(digits));
}
#pragma region shitty way
// vector<int> LeetCode2094Finding3DigitEvenNumbers::findEvenNumbers(vector<int> &digits) {
//     int length=static_cast<int>(digits.size());
//     unordered_set<int> result{};
//     vector<int> numbers{};
//     int number{};
//     for (int i = 0; i < length-2; i++) {
//         for (int j = i + 1; j < length-1; j++) {
//             for (int k = j + 1; k < length; k++) {
//                 numbers={digits[i],digits[j],digits[k]};
//                 for (int l = 0; l < 3; l++) {
//                     for (int m = 0; m < 3; m++) {
//                         if (m==l)
//                             continue;
//                         for (int n = 0; n < 3; n++) {
//                             if (n==l)
//                                 continue;
//                             if (n==m)
//                                 continue;
//                             number=numbers[l]*100+numbers[m]*10+numbers[n];
//                             if (number%2==1)
//                                 continue;
//                             if (number<100)
//                                 continue;
//                             result.insert(number);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     vector<int>output{};
//     for (auto number : result) {
//         output.push_back(number);
//     }
//     ranges::sort(output);
//     return output;
// }
#pragma endregion
