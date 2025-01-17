//
// Created by saeed on 1/17/25.
//

#ifndef LEETCODE214SHORTESTPALINDROME_H
#define LEETCODE214SHORTESTPALINDROME_H
#include <string>

#include "BaseProblem.h"


class LeetCode214ShortestPalindrome:  BaseProblem {
    private:
    std::string shortestPalindrome(std::string s);
    public:
    void Run() override;
};



#endif //LEETCODE214SHORTESTPALINDROME_H
