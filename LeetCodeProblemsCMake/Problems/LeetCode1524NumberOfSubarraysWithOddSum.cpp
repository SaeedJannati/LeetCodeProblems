//
// Created by saeed on 2/25/25.
//

#include "LeetCode1524NumberOfSubarraysWithOddSum.h"

int LeetCode1524NumberOfSubarraysWithOddSum::numOfSubarrays(std::vector<int> &arr) {
    int evenCount=1;
    int oddCount=0;
    int prefixSum=0;
    int modFactor=1e9+7;
    for (auto i:arr) {
        prefixSum+=i%2;
        prefixSum%=2;
        if (prefixSum==1) {
            oddCount++;
        }
        else {
            evenCount++;
        }
    }
    long long result = evenCount%modFactor;
    result*=oddCount%modFactor;
    result%=modFactor;
    return result;
}
