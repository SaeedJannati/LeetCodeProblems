//
// Created by saeed on 1/17/25.
//

#include "LeetCode214ShortestPalindrome.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string LeetCode214ShortestPalindrome::shortestPalindrome(std::string s) {
    if (s.empty()) return s;
    int length = static_cast<int>(s.length());
    if (length == 1) return s;
    bool isPalindrome = true;
    for (int i=0,e=length/2;i<e;i++) {
        if (s[i]!=s[length-i-1]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) {return s;}

    std::vector dp(length, std::vector(length, false));
    for (int i = 0; i < length; i++)
        dp[i][i] = true;
    for (int i = 0; i < length - 1; i++)
        dp[i][i + 1] = s[i] == s[i + 1];
    for (int i = 2; i < length; i++)
        for (int j = 0; j < length - i; j++) {
            if (s[j] != s[i + j]) {
                dp[j][j + i] = false;
                continue;
            }
            dp[j][j + i] = dp[j + 1][j + i - 1];
        }
    int longestPalindromeIndex = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (dp[0][i]) {
            longestPalindromeIndex = i;
            break;
        }
    }
    auto stringToAdd = s.substr(longestPalindromeIndex + 1);
    std::ranges::reverse(stringToAdd);
    return stringToAdd + s;
}

void LeetCode214ShortestPalindrome::Run() {
    std::string s = "aacecaaa";
    std::cout << shortestPalindrome(s) << std::endl;
}
