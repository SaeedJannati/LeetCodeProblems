//
// Created by saeed on 1/10/25.
//

#include "LeetCode1404NumberOfStepsToReduceANumberInBinaryRepresentationToOne.h"

#include <bitset>
#include <iostream>
#include <vector>

void AddOne(std::vector<bool> &num, int length) {
    bool carry = true;
    bool tempCarry;
    int currentDigit = length - 1;
    while (carry && currentDigit >=0) {
        tempCarry = carry & num[currentDigit];
        num[currentDigit] = carry ^ num[currentDigit];
        carry = tempCarry;
        currentDigit--;
    }
    if (!carry)
        return;
    num.insert(num.begin(), true);
}

int LeetCode1404NumberOfStepsToReduceANumberInBinaryRepresentationToOne::numSteps(std::string s) {
    int n = s.length();
    std::vector<bool> num;
    bool digit = false;
    for (auto &c: s) {
        digit = c != '0';
        num.push_back(digit);
    }
    int stepCount = 0;
    int size = num.size();
    while (size > 1) {
        if (num[size - 1] == false) {
            num.pop_back();
            size--;
            stepCount++;
            continue;
        }
        AddOne(num, size);
        size = num.size();
        stepCount++;
    }
    return stepCount;
}

void LeetCode1404NumberOfStepsToReduceANumberInBinaryRepresentationToOne::Run() {
    std::string s = "1101";
    std::cout << numSteps(s);
}
