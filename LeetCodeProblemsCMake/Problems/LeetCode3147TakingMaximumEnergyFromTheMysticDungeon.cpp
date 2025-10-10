//
// Created by saeed on 10/10/25.
//

#include "LeetCode3147TakingMaximumEnergyFromTheMysticDungeon.h"

#include <limits.h>
using namespace std;
int getEnergy(vector<int>& energies, vector<int> &memo,int length,int  k,int index) {
    if (memo[index]!=-1)
        return memo[index];
    if (index<k) {
        memo[index]=energies[index];
        return energies[index];
    }
    memo[index]=max(energies[index], energies[index]+getEnergy(energies,memo,length,k,index-k));
    return memo[index];
}
int LeetCode3147TakingMaximumEnergyFromTheMysticDungeon::maximumEnergy( vector<int> &energy, int k) {
    int length=static_cast<int> (energy.size());
    vector<int> prefixEnergy(length,-1);
    int maxEnergy=INT_MIN;
    for(int i=length-1;i>=length-k;i--) {
        maxEnergy=max(maxEnergy,getEnergy(energy,prefixEnergy,length,k,i));
    }
    return maxEnergy;
}
