//
// Created by saeed on 1/16/25.
//

#include "LeetCode43MultiplyStrings.h"

#include <iostream>
#include <ostream>
#include <vector>

void MultiplyByNum(int digit, std::vector<int> &num, std::vector<int> &result, int zeroCount) {
    int carry = 0;
    int numSize = num.size();
    std::vector<int> tempNum(num);
    for (int i = numSize - 1; i >= 0; i--) {
        int temp = (carry + digit * num[i]);
        carry = temp / 10;
        result[i] = temp % 10;
    }
    if (carry > 0) {
        result.insert(result.begin(), carry % 10);
    }
    if (carry > 9) {
        result.insert(result.begin(), carry / 10);
    }
    for (int i = 0; i < zeroCount; i++)
        result.push_back(0);
}

void Sum(std::vector<int> &num, std::vector<int> &result) {
    int carry = 0;
    int numSize = num.size();
    int resultSize = result.size();
    int minSize = std::min(numSize, resultSize);
    for (int i = 0; i < minSize; i++) {
        int temp = num[numSize - 1 - i] + result[resultSize - 1 - i] + carry;
        result[resultSize - 1 - i] = temp % 10;
        carry = temp / 10;
    }
    if (numSize > resultSize) {
        for (int i = minSize; i < numSize; i++) {
            int temp = num[numSize - 1 - i] + carry;
            result.insert(result.begin(), temp % 10);
            carry = temp / 10;
        }
        if (carry > 0) {
            result.insert(result.begin(), carry);
        }
        return;
    }
    for (int i = minSize; i < resultSize; i--) {
        int temp = result[i] + carry;
        result[i] = temp % 10;
        carry = temp / 10;
    }
    if (carry > 0) {
        result.insert(result.begin(), carry);
    }
}

std::string LeetCode43MultiplyStrings::multiply(std::string num1, std::string num2) {
    int len1 = static_cast<int>(num1.length());
    int len2 = static_cast<int>(num2.length());

    std::vector<int> first;
    first.reserve(len1);
    std::vector<int> second;
    second.reserve(len2);
    for (int i = 0; i < len1; i++) {
        first.push_back(num1[i] - '0');
    }
    for (int i = 0; i < len2; i++) {
        second.push_back(num2[i] - '0');
    }
    if (len1==1)
        if (first[0] ==0)
            return "0";
    if (len2 ==1)
        if (second[0] ==0)
            return "0";
    std::vector<int> result{};

    for (int i = len1 - 1; i >= 0; i--) {
        std::vector<int> temp = second;
        MultiplyByNum(first[i], second, temp, len1-1-i);
        Sum(temp, result);
    }
    std::string res = "";
    for (const int i: result) {
        res += std::to_string(i);
    }
    return res;
}

void LeetCode43MultiplyStrings::Run() {
    std::string num1 = "123";
    std::string num2 = "456";
    std::string result = multiply(num1, num2);
    std::cout << result << std::endl;
}
