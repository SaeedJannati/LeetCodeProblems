//
// Created by saeed on 1/4/25.
//

#include "LeetCode44WildcardMatching.h"

#include <iostream>
#include <ostream>
#include <vector>

bool LeetCode44WildcardMatching::isMatch(std::string s, std::string p) {
    const int sLength = static_cast<int>( s.length());
   const int pLength = static_cast<int>( p.length());
    if (sLength==0) {
        if (pLength== 0)
            return true;
        for (auto c:p) {
            if (c!='*')
                return false;
        }
        return  true;
    }
    if (pLength==0)
        return false;
    std::vector<std::vector<bool>> dp(sLength + 1, std::vector<bool>(pLength + 1, false));
    dp[0][0]= true;
    for (int i=1; i<sLength+1; i++) {
        dp[i][0]=false;
    }
    for (int i=1; i<pLength+1; i++) {
        dp[0][i]=dp[0][i-1]&&p[i-1]=='*';
    }
    for (int i=1; i<sLength+1; i++) {
        for (int j=1; j<pLength+1; j++) {
            if (p[j-1]=='*') {
                if (dp[i-1][j]||dp[i][j-1]) {
                    dp[i][j]=true;
                    continue;
                }

            }
            dp[i][j]=dp[i-1][j-1]&&( s[i-1]==p[j-1]|| p[j-1]=='*' || p[j-1]=='?');
        }
    }
    return dp[sLength][pLength];
}

void LeetCode44WildcardMatching::Run() {
   std::string s ="abcabczzzde";
       // "abcabczzzde";
    std::string p ="*abc???de*";
        // "*abc???de*";
    std::cout << isMatch(s, p) << std::endl;
}
