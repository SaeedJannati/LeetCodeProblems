//
// Created by saeed on 1/14/25.
//

#include "LeetCode115DistinctSubsequences.h"

#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

int LeetCode115DistinctSubsequences::numDistinct(std::string s, std::string t) {
    int sLength = s.size();
    int tLength = t.size();

    if (tLength>sLength)
        return 0;
    const int maxValue=std::numeric_limits<int>::max();
     std::vector<std::vector<int>> dp(tLength, std::vector<int>(sLength, 0));
    dp[0][0]=s[0]==t[0];
    for (int i=1; i<sLength; i++) {
        dp[0][i]=dp[0][i-1];
        if (s[i]==t[0])
            dp[0][i]++;
    }
    for (int i = 1; i < tLength; i++) {
        for (int j = i; j < sLength; j++) {
                dp[i][j]=dp[i][j-1];
            if (s[j]!=t[i])
                continue;
            // it said that result will fit in int 32 so anything above we won't keep we could have used long long but it is better solution memory wise
            // we could go further in memory omptimisatin via using just two rows of tlength size and keep last row only
            if (maxValue- dp[i][j]<dp[i-1][j-1])
                continue;
            dp[i][j]+=dp[i-1][j-1];
        }
    }
    return dp[tLength-1][sLength-1];
}

void LeetCode115DistinctSubsequences::Run() {
    std::string s = "rabbbit";
    std::string t = "rabbit";
    int num = numDistinct(s, t);
    std::cout << num << std::endl;
}
