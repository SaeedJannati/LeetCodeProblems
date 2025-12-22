//
// Created by saeed on 12/22/25.
//

#include "GeeksForGeeksLongestIncreasingSubsequence.h"
using namespace std;
int getLis(vector<int>& arr,vector<int>&dp,int index) {
    if (dp[index]!=-1)
        return dp[index];
    int maxLength=1;
    for (int i=0;i<index;i++) {
        if (arr[i]<arr[index]) {
            int currentLength=getLis(arr,dp,i)+1;
            maxLength=max(maxLength,currentLength);
        }
    }
    dp[index]=maxLength;
    return dp[index];
}
int GeeksForGeeksLongestIncreasingSubsequence::lis(vector<int> &arr) {
    int length=static_cast<int>(arr.size());
    vector<int> dp(length,-1);
    getLis(arr,dp,length-1);
    int maxLength=1;
    for (int i=0;i<length;i++) {
        maxLength=max(maxLength,getLis(arr,dp,i));
    }
    return maxLength;
}
