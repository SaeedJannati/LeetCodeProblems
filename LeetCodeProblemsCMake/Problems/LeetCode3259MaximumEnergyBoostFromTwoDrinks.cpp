//
// Created by Saeed Jannati on 5/11/2026 A.
//

#include "LeetCode3259MaximumEnergyBoostFromTwoDrinks.h"
using namespace std;

long long LeetCode3259MaximumEnergyBoostFromTwoDrinks::maxEnergyBoost(vector<int> &energyDrinkA,
                                                                      vector<int> &energyDrinkB) {
    int length = static_cast<int>(energyDrinkA.size());
    vector<long long> dpA = {energyDrinkA[0], energyDrinkA[0]+energyDrinkA[1], 0};
    vector<long long> dpB = {energyDrinkB[0], energyDrinkB[0]+energyDrinkB[1], 0};
    for (int i = 2; i < length; i++) {
        dpA[2] = max(dpA[1], dpB[0]) + energyDrinkA[i];
        dpB[2] = max(dpB[1], dpA[0]) + energyDrinkB[i];
        dpA[0] = dpA[1];
        dpA[1] = dpA[2];
        dpB[0] = dpB[1];
        dpB[1] = dpB[2];
    }
    return max(dpA[2], dpB[2]);
}
