//
// Created by saeed on 12/24/25.
//

#include "LeetCode3074AppleRedistributionIntoBoxes.h"

#include <algorithm>
#include <numeric>
using namespace std;

int LeetCode3074AppleRedistributionIntoBoxes::minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    ranges::sort(capacity, std::greater<>{});
    int sumApples=accumulate(apple.begin(), apple.end(), 0);
    int result{};
    int currentSum{};;
    int length=static_cast<int>(capacity.size());
    for (int i=0; i<length; ++i) {
        currentSum+=capacity[i];
        ++result;
        if (currentSum>=sumApples) {
            return result;
        }

    }
    return result;
}
