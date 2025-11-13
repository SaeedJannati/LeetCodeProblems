//
// Created by saeed on 11/13/25.
//

#include "LeetCode3228MaximumNumberOfOperationsToMoveOnesToTheEnd.h"

#include <vector>
using namespace std;

int LeetCode3228MaximumNumberOfOperationsToMoveOnesToTheEnd::maxOperations(string s) {
    int length= static_cast<int>(s.length());
    int moveCount{};
    vector<int> prefixSum(length,0);
    prefixSum[0]= s[0]=='1'?1:0;
    for(int i=1;i<length;++i) {
        prefixSum[i]=prefixSum[i-1]+(s[i]=='1'?1:0);
    }
    for (int i=1;i<length;++i) {
        if (s[i]=='1' && s[i-1]=='0') {
            moveCount+=prefixSum[i]-1;
        }
    }
    if (s[length-1]=='0')
        moveCount+=prefixSum[length-1];
    return moveCount;
}
