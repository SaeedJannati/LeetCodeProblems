//
// Created by saeed on 1/30/26.
//

#include "LeetCode1458MaxDotProductOfTwoSubsequences.h"

#include <stdint.h>
using namespace std;
int calcDp(vector<int>& nums1,vector<int>& nums2, vector<vector<int>>& dp,int length1,int length2,int first,int second) {
    if (first>=length1) {
        return INT32_MIN;
    }
    if (second>=length2) {
        return INT32_MIN;
    }
    if (dp[first][second]!=INT32_MIN) {
        return dp[first][second];
    }
    dp[first][second]= nums1[first]*nums2[second];
    int next=calcDp(nums1,nums2,dp,length1,length2,first+1,second+1);
    if (next>0) {
        dp[first][second]+=next;
    }
    dp[first][second]=max(dp[first][second],calcDp(nums1,nums2,dp,length1,length2,first+1,second));
    dp[first][second]=max(dp[first][second],calcDp(nums1,nums2,dp,length1,length2,first,second+1));
    return dp[first][second];
}
int LeetCode1458MaxDotProductOfTwoSubsequences::maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    int length1 =static_cast<int>(  nums1.size());
    int length2 = static_cast<int>(nums2.size());

    auto dp=vector<vector<int>>(length1, vector<int>(length2, INT32_MIN));
    int result= INT32_MIN;
    for (int i=0;i<length1;i++) {
        for (int j=0;j<length2;j++) {
            result=max(result,calcDp(nums1,nums2,dp,length1,length2,i,j) );
        }
    }
    return result;
}
