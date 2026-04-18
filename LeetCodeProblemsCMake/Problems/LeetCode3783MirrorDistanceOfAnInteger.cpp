//
// Created by Saeed Jannati on 4/18/2026 A.
//

#include "LeetCode3783MirrorDistanceOfAnInteger.h"

#include <iostream>
#include <string>

using  namespace std;
int LeetCode3783MirrorDistanceOfAnInteger::mirrorDistance(int n) {
    string digits{};
    long  reversed{n};
    while (reversed>0) {
        digits.push_back(reversed%10+'0');
        reversed = reversed/10;
    }
    for (auto digit : digits) {
        reversed+=(digit-'0');
        reversed*=10;
    }
    reversed/=10;
    return abs(reversed-long (n));
}

void LeetCode3783MirrorDistanceOfAnInteger::Run() {
    int n=25;
    cout<<mirrorDistance(n)<<'\n';
}
