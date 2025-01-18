//
// Created by saeed on 1/18/25.
//

#include "LeetCode743NetworkDelayTime.h"

#include <iostream>
#include <limits>
#include <ostream>
#include <unordered_map>
#include <unordered_set>

int LeetCode743NetworkDelayTime::networkDelayTime(std::vector<std::vector<int> > &times, int n, int k) {
    std::unordered_map<int, std::unordered_map<int, int> > adjPlus{};
    int edgeCount = static_cast<int>(times.size());
    for (int i = 0; i < edgeCount; i++) {
        if (!adjPlus.contains(times[i][0]-1)) {
            adjPlus[times[i][0]-1] = std::unordered_map<int, int>{};
        }
        if (!adjPlus[times[i][0]-1].contains(times[i][1]-1)) {
            adjPlus[times[i][0]-1][times[i][1]-1] = times[i][2];
        }
    }
    const int maxInt = std::numeric_limits<int>::max();
    std::vector duplicatedGraph(n, std::vector(n, maxInt));
    duplicatedGraph[0][k - 1] = 0;
    for (int i =0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            if (duplicatedGraph[i][j] != maxInt) {
                duplicatedGraph[i+1][j]=std::min(duplicatedGraph[i+1][j], duplicatedGraph[i][j]);
                for (auto& edge : adjPlus[j]) {
                    if (duplicatedGraph[i+1][edge.first]>duplicatedGraph[i][j]+edge.second) {
                        duplicatedGraph[i+1][edge.first] = duplicatedGraph[i][j]+edge.second;
                    }
                }
            }
        }
    }
    int maxTime=std::numeric_limits<int>::min();
    for (const auto& time : duplicatedGraph[n-1]) {
        if (time==maxInt)
            return -1;
        if (time>maxTime)
            maxTime=time;
    }
    return maxTime;
}

void LeetCode743NetworkDelayTime::Run() {
    std::vector< std::vector<int> > times{{2,1,1},{2,3,1},{3,4,1}};
    int n=4;
    int k=2;
    auto time=networkDelayTime(times, n, k);
    std::cout<<"Time is "<<time<<std::endl;
}
