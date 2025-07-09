//
// Created by saeed on 5/2/25.
//

#include "LeetCode838PushDominoes.h"

#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

string LeetCode838PushDominoes::pushDominoes(string dominoes) {
    int length = static_cast<int>(dominoes.size());
    vector<int> dominoesVector(length, 0);
    vector<bool> visited(length, false);
    queue<int> currentLayer{};
    queue<int> nextLayer{};
    for (int i = 0; i < length; i++) {
        switch (dominoes[i]) {
            case 'R':
                dominoesVector[i] = 1;
                break;
            case 'L':
                dominoesVector[i] = -1;
                break;
            case '.':
                dominoesVector[i] = 0;
                break;
        }
        if (dominoesVector[i] != 0) {
            currentLayer.push(i);
            visited[i] = true;
        }
    }
    unordered_set<int> dominoesSet{};
    while (!currentLayer.empty()) {
        while (!currentLayer.empty()) {
            auto current = currentLayer.front();
            currentLayer.pop();
            switch (dominoesVector[current]) {
                case 1:
                    if (current+1<length && !visited[current+1]) {
                        dominoesVector[current+1] = std::min(dominoesVector[current+1]+1, 1);
                        dominoesSet.insert(current+1);
                    }
                    break;
                case -1:
                    if (current-1>-1 && !visited[current-1]) {
                        dominoesVector[current-1] = std::max(dominoesVector[current-1]-1, -1);
                        dominoesSet.insert(current-1);
                    }
                    break;
            }
        }
       for (auto current : dominoesSet) {
            currentLayer.push(current);
           visited[current] = true;
        }
        dominoesSet.clear();
    }
   for (int i = 0; i < length; i++) {
       switch (dominoesVector[i]) {
           case 1:
               dominoes[i] = 'R';
           break;
           case -1:
               dominoes[i] = 'L';
           break;
           case 0:
               dominoes[i] = '.';
           break;
       }
   }
    return dominoes;
}

void LeetCode838PushDominoes::Run() {
    string dominoes = ".L.R...LR..L..";
    cout<<pushDominoes(dominoes)<<endl;
}
