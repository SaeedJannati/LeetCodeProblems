//
// Created by saeed on 1/29/25.
//

#include "LeetCode96UniqueBinarySearchTrees.h"

#include <iostream>
#include <ostream>
#include <vector>
int CalculateTreeNumber(int n,std::vector<int>& dp) {
    if (dp[n]!=0) {
        return dp[n];
    }
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum+=CalculateTreeNumber(i,dp)*CalculateTreeNumber(n-i-1,dp);
    }
    dp[n] = sum;
    return dp[n];
}
int LeetCode96UniqueBinarySearchTrees::numTrees(int n) {
    std::vector<int> dp(n+1 , 0);
    dp[0]=1;
    dp[1]=1;
    if (n<=1)
        return dp[n];
    return CalculateTreeNumber(n,dp);
}

void LeetCode96UniqueBinarySearchTrees::Run() {
    int n=3;
    std::cout<<numTrees(n)<<std::endl;
}
