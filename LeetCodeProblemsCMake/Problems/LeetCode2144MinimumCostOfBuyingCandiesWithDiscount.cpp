//
// Created by Saeed Jannati on 6/1/26.
//
using namespace std;
#include "LeetCode2144MinimumCostOfBuyingCandiesWithDiscount.h"

int LeetCode2144MinimumCostOfBuyingCandiesWithDiscount::minimumCost(vector<int> &cost) {
    ranges::sort(cost);
    int index{static_cast<int>(cost.size())-1};
    int spent{};
    while (index >= 0) {
        for (int i = 0; i < 2; ++i) {
            spent += cost[index--];
            if (index < 0) {
                break;
            }
        }
        --index;
    }
    return spent;
}
