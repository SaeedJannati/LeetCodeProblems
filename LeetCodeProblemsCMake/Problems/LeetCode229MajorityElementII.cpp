//
// Created by saeed on 6/30/25.
//

#include "LeetCode229MajorityElementII.h"
using namespace std;

vector<int> LeetCode229MajorityElementII::majorityElement(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    int firstCandidate = 0;
    int secondCandidate = 0;
    int firstVotes{0};
    int secondVotes{0};
    for (auto num: nums) {
        if (num == firstCandidate) {
            firstVotes++;
        } else if (num == secondCandidate) {
            secondVotes++;
        } else if (firstVotes == 0) {
            firstCandidate = num;
            firstVotes = 1;
        } else if (secondVotes == 0) {
            secondCandidate = num;
            secondVotes = 1;
        } else {
            firstVotes--;
            secondVotes--;
        }
    }
    firstVotes = 0;
    secondVotes = 0;
    for (auto num: nums) {
        if (num == firstCandidate) {
            firstVotes++;
        } else if (num == secondCandidate) {
            secondVotes++;
        }
    }
    vector<int> result{};
    if (firstVotes>length/3)
        result.push_back(firstCandidate);
    if (secondVotes>length/3)
        result.push_back(secondCandidate);
    return result;
}
