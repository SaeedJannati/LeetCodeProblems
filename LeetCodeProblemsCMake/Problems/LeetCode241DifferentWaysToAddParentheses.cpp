//
// Created by saeed on 2/7/25.
//

#include "LeetCode241DifferentWaysToAddParentheses.h"

#include <cmath>
#include <stack>

#include "../Auxilary/Auxilaries.h"

std::vector<int> GetAnswer(std::vector<int> &numbers, std::vector<char> &operators,std::vector<std::vector<std::vector<int>>>& dp, int beginIndex, int endIndex) {

    if (!dp[beginIndex][endIndex].empty()) {
        return dp[beginIndex][endIndex];
    }
    if (beginIndex == endIndex) {
        dp[beginIndex][beginIndex]= {numbers[beginIndex]};
        return dp[beginIndex][beginIndex];
    }
    for (int i = beginIndex; i < endIndex; i++) {
        auto firstPart = GetAnswer(numbers, operators,dp, beginIndex, i);
        auto secondPart = GetAnswer(numbers, operators,dp, i + 1, endIndex);
        for (auto firstNum:firstPart) {
            for (auto secondNum:secondPart) {
                switch (operators[i]) {
                    case '+':
                        dp[beginIndex][endIndex].push_back(firstNum + secondNum);
                        break;
                    case '-':
                        dp[beginIndex][endIndex].push_back(firstNum - secondNum);
                        break;
                    case '*':
                        dp[beginIndex][endIndex].push_back(firstNum * secondNum);
                        break;
                }
            }
        }
    }
    return dp[beginIndex][endIndex];
}

std::vector<int> LeetCode241DifferentWaysToAddParentheses::diffWaysToCompute(std::string expression) {
    std::vector<char> operators{};
    std::vector<int> numbers{};
    std::stack<int> numStack;
    int nextNum{};
    int powOfTenCounter{};
    for (auto &c: expression) {
        if (c >= '0' && c <= '9') {
            numStack.push(c - '0');
            continue;
        }
        nextNum = 0;
        powOfTenCounter = 0;
        while (!numStack.empty()) {
            nextNum += numStack.top() * std::pow(10, powOfTenCounter);
            powOfTenCounter++;
            numStack.pop();
        }
        numbers.push_back(nextNum);
        operators.push_back(c);
    }
    if (!numStack.empty()) {
        nextNum = 0;
        powOfTenCounter = 0;
        while (!numStack.empty()) {
            nextNum += numStack.top() * std::pow(10, powOfTenCounter);
            powOfTenCounter++;
            numStack.pop();
        }
        numbers.push_back(nextNum);
    }
    int numsSize = static_cast<int>(numbers.size());
    std::vector dp(numsSize, std::vector(numsSize, std::vector<int>()));
    return GetAnswer(numbers, operators, dp, 0, numsSize-1);
}

void LeetCode241DifferentWaysToAddParentheses::Run() {
    std::string expression="2*3-4*5";
    Auxilaries::PrintVector(diffWaysToCompute(expression));
}
