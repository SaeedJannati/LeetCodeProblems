//
// Created by saeed on 3/6/25.
//

#include "LeetCode2965FindMissingAndRepeatedValues.h"

#include <numeric>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"
#pragma region O(1) memory
std::vector<int> LeetCode2965FindMissingAndRepeatedValues::findMissingAndRepeatedValues(
    std::vector<std::vector<int> > &grid) {
    int length = grid.size();
    int totalLength = length * length;
    long long sum=(1+totalLength)*(totalLength)/2;
    long long sqrSum{};
    long long currentsSum{};
    long long currentSqrSum{};
    std::vector<int> result{};
    result.reserve(2);
    int counter{};
    for(int i=0;i<length;i++) {
        for(int j=0;j<length;j++) {
            currentSqrSum+=grid[i][j]*grid[i][j];
            currentsSum+=grid[i][j];
            counter=i*length+j+1;
            sqrSum+=counter*counter;
        }
    }
    long long deltaSqr=currentSqrSum-sqrSum;
    int delta=currentsSum-sum;
    int addition=deltaSqr/delta;
    result.push_back((addition+delta)/2);
    result.push_back((addition-delta)/2);
    return result;
}

void LeetCode2965FindMissingAndRepeatedValues::Run() {
    std::vector<std::vector<int> > grid
    // {{9,1,7},{8,9,2},{3,4,6}};
    {{1,3},{2,2}};
    Auxilaries::PrintVector(findMissingAndRepeatedValues(grid));
}
#pragma endregion
#pragma region O(n^2) memory
// std::vector<int> LeetCode2965FindMissingAndRepeatedValues::findMissingAndRepeatedValues(
//     std::vector<std::vector<int> > &grid) {
//     int length = grid.size();
//     std::unordered_set<int> pool{};
//     for (int i = 0, e = length * length; i < e; i++) {
//         pool.insert(i + 1);
//     }
//     std::vector<int> result{};
//     for (int i = 0; i < length; i++) {
//         for (int j = 0; j < length; j++) {
//             if (pool.contains(grid[i][j])) {
//                 pool.erase(grid[i][j]);
//                 continue;
//             }
//             result.push_back(grid[i][j]);
//         }
//     }
//     result.push_back(*pool.begin());
//     return result;
// }
#pragma endregion order n^2 memory
