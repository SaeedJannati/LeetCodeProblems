//
// Created by saeed on 6/1/25.
//

#include "LeetCode2929DistributeCandiesAmongChildrenII.h"

#include <algorithm>
#include <iostream>
#include <ostream>
using namespace std;
long long LeetCode2929DistributeCandiesAmongChildrenII::distributeCandies(int n, int limit) {
    int minLim=std::min(n,limit);
    long long sum=0;
    long long stepCombinations=0;
    for(int i=0;i<=minLim;i++) {
        stepCombinations=std::max(std::min(n,i+minLim)-std::max(i,n-minLim)+1,0);
        sum+=stepCombinations;
    }
    return sum;
}

void LeetCode2929DistributeCandiesAmongChildrenII::Run() {
    int n=3;
    int limit=3;
    cout<<distributeCandies(n,limit)<<endl;
}
