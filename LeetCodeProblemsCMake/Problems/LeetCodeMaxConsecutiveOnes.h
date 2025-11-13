//
// Created by saeed on 11/13/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODEMAXCONSECUTIVEONES_H
#define LEETCODEPROBLEMSCMAKE_LEETCODEMAXCONSECUTIVEONES_H
#include <vector>

using namespace std;
class LeetCodeMaxConsecutiveOnes {
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveOnes = 0;
        int currentConsecutiveOnes = 0;
        for ( auto num : nums ) {
            if ( num == 1 ) {
                ++currentConsecutiveOnes;
                continue;
            }
            maxConsecutiveOnes = max(maxConsecutiveOnes, currentConsecutiveOnes);
            currentConsecutiveOnes = 0;
        }
        maxConsecutiveOnes = max(maxConsecutiveOnes, currentConsecutiveOnes);
        return maxConsecutiveOnes;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODEMAXCONSECUTIVEONES_H