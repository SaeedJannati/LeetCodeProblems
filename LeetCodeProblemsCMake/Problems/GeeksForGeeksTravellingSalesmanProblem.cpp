//
// Created by saeed on 5/19/25.
//

#include "GeeksForGeeksTravellingSalesmanProblem.h"

#include <iostream>
#include <limits>
using namespace std;
int getTotalCost(int mask,int current,vector<vector<int>> &cost,int length,int maxMask,vector<vector<int>>& bitMaskDp,int infinity) {
    if (bitMaskDp[mask][current] != infinity) {
        return bitMaskDp[mask][current];
    }
    if (mask == maxMask){
        bitMaskDp[mask][current]= cost[current][0];
        return bitMaskDp[mask][current];
    }
    for(int i=0;i<length;i++) {
        if(mask & (1<<i))
            continue;
        bitMaskDp[mask][current]=std::min(bitMaskDp[mask][current],getTotalCost(mask|(1<<i),i,cost,length,maxMask,bitMaskDp,infinity)+cost[current][i]);
    }
    return bitMaskDp[mask][current];
}
int GeeksForGeeksTravellingSalesmanProblem::tsp(std::vector<std::vector<int>> &cost) {
    int length= static_cast<int>(cost.size());
    int maxBitMask=(1<<length);
    int infinity=std::numeric_limits<int>::max()/2;
    vector<vector<int>> bitMaskDp(maxBitMask,vector<int>(length,infinity));
    return getTotalCost(1,0,cost,length,maxBitMask-1,bitMaskDp,infinity);
}

void GeeksForGeeksTravellingSalesmanProblem::Run() {
    vector<vector<int>> cost{{0, 1000, 5000}, {5000, 0, 1000}, {1000, 5000, 0}};
    cout<<tsp(cost)<<'\n';
}

