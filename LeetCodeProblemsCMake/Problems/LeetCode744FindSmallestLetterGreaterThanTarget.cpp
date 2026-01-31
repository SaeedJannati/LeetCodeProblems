//
// Created by Saeed Jannati on 1/31/2026 A.
//

#include "LeetCode744FindSmallestLetterGreaterThanTarget.h"
using namespace std;

char LeetCode744FindSmallestLetterGreaterThanTarget::nextGreatestLetter(vector<char> &letters, char target) {
    if (target=='z') {
        return letters[0];
    }
    int length= static_cast<int>(letters.size());
    int begin{0};
    int end{length-1};
    int mid{0};
    int found{length};
    while (begin<=end) {
        mid=(begin+end)>>1;
        if (letters[mid]>target) {
            found=min(found,mid);
            end=mid-1;
            continue;
        }
        begin=mid+1;
    }
    if (found==length) {
        return letters[0];
    }
    return letters[found];
}
