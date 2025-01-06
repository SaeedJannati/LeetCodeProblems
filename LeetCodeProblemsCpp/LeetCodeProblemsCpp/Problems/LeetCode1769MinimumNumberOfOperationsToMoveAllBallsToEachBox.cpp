#include "LeetCode1769MinimumNumberOfOperationsToMoveAllBallsToEachBox.h"

std::vector<int> LeetCode1769MinimumNumberOfOperationsToMoveAllBallsToEachBox::minOperations(std::string boxes)
{
    int size = static_cast<int>( boxes.size());
    std::vector<int> result(size,0);
    std::vector<int> prefix(size,0);
    std::vector<int> suffix(size,0);
    int oneCounts=0;
    for (int i = 1; i < size; i++)
    {
        oneCounts+= boxes[i-1]-'0';
        prefix[i] = prefix[i - 1]+oneCounts ;
    }
    oneCounts=0;
    for (int i=size-2;i>=0;i--)
    {
        oneCounts+=boxes[i+1]-'0';
        suffix[i]=suffix[i+1] + oneCounts;
        result[i]=prefix[i] + suffix[i];
    }
    result[size-1] = prefix[size-1];
    return result;
}
