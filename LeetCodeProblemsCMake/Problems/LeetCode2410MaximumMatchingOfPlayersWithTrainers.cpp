//
// Created by saeed on 7/13/25.
//

#include "LeetCode2410MaximumMatchingOfPlayersWithTrainers.h"

#include <algorithm>
using namespace std;
int LeetCode2410MaximumMatchingOfPlayersWithTrainers::matchPlayersAndTrainers( vector<int> &players,  vector<int> &trainers) {
    ranges::sort(trainers);
    ranges::sort(players);
    int result{};
    int playersPointer{};
    int trainersPointer{};
    int playersLength= players.size();
    int trainersLength = trainers.size();
    while (playersPointer < playersLength && trainersPointer < trainersLength) {
        if (players[playersPointer] > trainers[trainersPointer]) {
            trainersPointer++;
            continue;
        }
        playersPointer++;
        trainersPointer++;
        result++;
    }
    return  result;
}
