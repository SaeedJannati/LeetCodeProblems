//
// Created by Saeed Jannati on 6/28/26.
//

#include "LeetCode1846MaximumElementAfterDecreasingAndRearranging.h"
using namespace std;

int LeetCode1846MaximumElementAfterDecreasingAndRearranging::maximumElementAfterDecrementingAndRearranging(
    vector<int> &arr) {
    int length = static_cast<int>(arr.size());
    vector<int> occurrences=vector<int>(length+1);
    for (auto num:arr) {
        ++occurrences[ min(num,length)];
    }
    int result{1};
    for (int i=2;i<=length;++i) {
        result= min(result + occurrences[i],i);
    }
    return result;
}
