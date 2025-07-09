//
// Created by saeed on 6/8/25.
//

#include "LeetCode386LexicographicalNumbers.h"
using namespace std;
void Dfs( vector<int> & result,int n,int currentNum) {

    if (currentNum>n)
        return;
    result.push_back(currentNum);
    currentNum*=10;
    int next{};
    for (int i=0;i<=9;i++) {
        next=currentNum+i;
        if (next>n)
            return;
        Dfs(result,n,next);
    }
}
 vector<int> LeetCode386LexicographicalNumbers::lexicalOrder(int n) {
    vector<int> result{};
     for (int i=1;i<=9;i++) {
         Dfs(result,n,i);
     }
    return result;
}
