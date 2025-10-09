//
// Created by saeed on 10/9/25.
//

#include "LeetCode3494FindTheMinimumAmountOfTimeToBrewPotions.h"
using namespace std;

long long LeetCode3494FindTheMinimumAmountOfTimeToBrewPotions::
minTime(vector<int> &skills, vector<int> &manas) {
    int skillSize = static_cast<int>(skills.size());
    int manaSize = static_cast<int>(manas.size());
    vector<long long> endTimes(skillSize , 0);
    vector<long long> roundPrefixSum(skillSize , 0);
    long long roundStartTime{};
    for (const auto mana : manas ) {
        for (int i = 1; i < skillSize; i++) {
            roundPrefixSum[i]=skills[i-1]*mana;
            roundPrefixSum[i]+=roundPrefixSum[i-1];
        }
        roundStartTime=0;
        for (int i=0; i < skillSize; i++) {
            roundStartTime=max(roundStartTime,endTimes[i]-roundPrefixSum[i]);
        }
        for (int i=0; i < skillSize; i++) {
            endTimes[i]=roundPrefixSum[i]+roundStartTime+mana*skills[i];
        }
    }
    return endTimes[skillSize-1];
}
