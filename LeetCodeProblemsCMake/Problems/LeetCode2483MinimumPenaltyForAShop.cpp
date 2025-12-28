//
// Created by saeed on 12/26/25.
//

#include "LeetCode2483MinimumPenaltyForAShop.h"

#include <vector>
using namespace std;

int LeetCode2483MinimumPenaltyForAShop::bestClosingTime(string customers) {
    int length = static_cast<int>(customers.length());
    vector<int> prefixSum(length+1, 0);
    vector<int> suffixSum(length+1,0);
    for (int i=1; i<=length; ++i) {
        prefixSum[i]=prefixSum[i-1]+(customers[i-1]=='N'?1:0);
    }
    for (int i=length-1; i>=0; --i) {
        suffixSum[i]=suffixSum[i+1]+(customers[i]=='Y'?1:0);
    }
    int minPenalty=length;
    int minIndex{-1};
    for (int i=0;i<=length;++i) {
        if ( suffixSum[i]+prefixSum[i]<minPenalty) {
            minPenalty=suffixSum[i]+prefixSum[i];
            minIndex=i;
        }
    }
    return minIndex;
}
