//
// Created by saeed on 3/8/25.
//

#include "LeetCode2379MinimumRecolorsToGetKConsecutiveBlackBlocks.h"

#include <limits>

int LeetCode2379MinimumRecolorsToGetKConsecutiveBlackBlocks::minimumRecolors(std::string blocks, int k) {
    int length = static_cast<int>(blocks.length());
    if (length == 1)
        return blocks[0] == 'W' ? 1 : 0;
    int minWhiteCount{};
    int whiteCount=0;
    for(int i=0;i<k;i++) {
        if(blocks[i] == 'W')
            whiteCount++;
    }
    minWhiteCount=whiteCount;
    for (int i=k; i<length; i++) {
        if(blocks[i] == 'W')
            whiteCount++;
        if (blocks[i-k] == 'W')
            whiteCount--;
        if (whiteCount < minWhiteCount)
            minWhiteCount = whiteCount;
    }
    return minWhiteCount;
}
