//
// Created by saeed on 10/30/25.
//

#include "LeetCode1526MinimumNumberOfIncrementsOnSubarraysToFormATargetArray.h"

#include <iostream>
#include <ostream>
using namespace std;


int LeetCode1526MinimumNumberOfIncrementsOnSubarraysToFormATargetArray::minNumberOperations(vector<int> &target) {
    int length = static_cast<int>(target.size());
    int moves{target[0]};
    for (int i = 1; i < length; i++) {
        moves+=max(target[i]-target[i-1], 0);
    }
    return moves;
}

void LeetCode1526MinimumNumberOfIncrementsOnSubarraysToFormATargetArray::Run() {
    vector<int> target = {1, 2, 3, 2, 1};
    cout << minNumberOperations(target) << endl;
}
