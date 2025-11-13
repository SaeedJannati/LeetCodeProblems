//
// Created by saeed on 11/13/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODECONCATENATIONOFARRAY_H
#define LEETCODEPROBLEMSCMAKE_LEETCODECONCATENATIONOFARRAY_H
#include <vector>

using namespace std;
class LeetCodeConcatenationOfArray {
    vector<int> getConcatenation(vector<int> &nums) {
        int length = static_cast<int>( nums.size());
        vector<int> result(2*length);
        for (int i=0; i<length; i++) {
            result[i] = nums[i];
            result[i+length] = nums[i];
        }
        return result;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODECONCATENATIONOFARRAY_H