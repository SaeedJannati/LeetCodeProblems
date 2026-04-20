//
// Created by Saeed Jannati on 4/20/2026 A.
//

#include "LeetCode2078TwoFurthestHousesWithDifferentColors.h"

#include <iostream>
#include <ostream>

using namespace std;
int LeetCode2078TwoFurthestHousesWithDifferentColors::maxDistance(vector<int> &colors) {
    int length= static_cast<int>(colors.size());
    int delta{};
    for (int i=length-1;i>0;i--) {
        if (colors[i]!=colors[0]) {
            delta=i;
            break;
        }
    }
    for (int i=0;i<length-1;i++) {
        if (colors[i]!=colors[length-1]) {
            return max(delta,length-i);
        }
    }
    return 0;
}

void LeetCode2078TwoFurthestHousesWithDifferentColors::Run() {
    vector<int> colors{1,1,1,6,1,1,1};
    cout<<maxDistance(colors)<<'\n';
}
