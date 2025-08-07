//
// Created by saeed on 8/7/25.
//

#include "LeetCode3363FindTheMaximumNumberOfFruitsCollected.h"

#include <iostream>
#include <ostream>
#include <queue>
using namespace std;

int LeetCode3363FindTheMaximumNumberOfFruitsCollected::maxCollectedFruits(vector<vector<int> > &fruits) {
    int length=static_cast<int>(fruits.size());
    int result=0;
    for (int i=0;i<length;i++) {
        result+=fruits[i][i];
        fruits[i][i]=0;
    }
    vector<vector<int>> dp(length,vector<int>(length,0));
    dp[0][length-1]=fruits[0][length-1];
    queue<pair<int,int>> currenLayer{};
    queue<pair<int,int>> nextLayer{};
    currenLayer.emplace(0,length-1);
    vector<pair<int,int>> dircetions={{1,-1},{1,0},{1,1}};
    vector<vector<bool>> visited(length,vector<bool>(length,false));
    visited[0][0]=true;
    int newHeight{};
    int newWidth{};
    int potentialFruits{};
    for (int i=1;i<length;i++) {
        while (!currenLayer.empty()) {
            auto coord=currenLayer.front();
            currenLayer.pop();
            for (auto & dir:dircetions) {
                newHeight=coord.first+dir.first;
                if (newHeight<0||newHeight>length-1)
                    continue;
                newWidth=coord.second+dir.second;
                if (newWidth<0||newWidth>length-1)
                    continue;
                if (newWidth<newHeight)
                    continue;
                potentialFruits=dp[coord.first][coord.second]+fruits[newHeight][newWidth];
                if (potentialFruits>dp[newHeight][newWidth]) {
                    dp[newHeight][newWidth]=potentialFruits;
                }
                if (visited[newHeight][newWidth])
                    continue;
                visited[newHeight][newWidth]=true;
                nextLayer.emplace(newHeight,newWidth);
            }
        }
        while (!nextLayer.empty()) {
            currenLayer.emplace(nextLayer.front());
            nextLayer.pop();
        }
    }
    result+=dp[length-1][length-1];
    for (int i=0;i<length;i++) {
        visited[i][i]=false;
        dp[i][i]=0;
    }
    dircetions={{1,1},{-1,1},{0,1}};
    currenLayer={};
    nextLayer={};
    currenLayer.emplace(length-1,0);
    visited[0][length-1]=true;
    dp[length-1][0]=fruits[length-1][0];
    for (int i=1;i<length;i++) {
        while (!currenLayer.empty()) {
            auto coord=currenLayer.front();
            currenLayer.pop();
            for (auto & dir:dircetions) {
                newHeight=coord.first+dir.first;
                if (newHeight<0||newHeight>length-1)
                    continue;
                newWidth=coord.second+dir.second;
                if (newWidth<0||newWidth>length-1)
                    continue;
                if (newWidth>newHeight)
                    continue;
                potentialFruits=dp[coord.first][coord.second]+fruits[newHeight][newWidth];
                if (potentialFruits>dp[newHeight][newWidth]) {
                    dp[newHeight][newWidth]=potentialFruits;
                }
                if (visited[newHeight][newWidth])
                    continue;
                visited[newHeight][newWidth]=true;
                nextLayer.emplace(newHeight,newWidth);
            }
        }
        while (!nextLayer.empty()) {
            currenLayer.emplace(nextLayer.front());
            nextLayer.pop();
        }
    }
    result+=dp[length-1][length-1];
    return result;
}

void LeetCode3363FindTheMaximumNumberOfFruitsCollected::Run() {
    vector<vector<int>> fruits={{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
    cout<<maxCollectedFruits(fruits)<<endl;
}
