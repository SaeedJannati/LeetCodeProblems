//
// Created by saeed on 11/19/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODECANMAKEARITHMETICPROGRESSIONFROMSEQUENCE_H
#define LEETCODEPROBLEMSCMAKE_LEETCODECANMAKEARITHMETICPROGRESSIONFROMSEQUENCE_H
#include <algorithm>
#include <vector>

using namespace std;
class LeetCodeCanMakeArithmeticProgressionFromSequence {
    bool canMakeArithmeticProgression(vector<int>& arr) {
        ranges::sort(arr);
        int diff=arr[1]-arr[0];
        for(int i=2,e=arr.size();i<e;++i) {
            if (arr[i]-arr[i-1]!=diff) {
                return false;
            }
        }
        return true;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODECANMAKEARITHMETICPROGRESSIONFROMSEQUENCE_H