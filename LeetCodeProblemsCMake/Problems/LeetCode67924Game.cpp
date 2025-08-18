//
// Created by saeed on 8/18/25.
//

#include "LeetCode67924Game.h"

#include <iostream>
#include <numeric>
#include <ostream>
using namespace std;



double applySign(double a, double b, char sign) {
    switch (sign) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
        case 3:
            return a / b;
    }
    return 0;
}

bool CheckNums(vector<int> &cards, vector<bool> &visited, vector<char> signs, vector<double> &nums, int index,
               bool & result) {
    if (result)
        return true;
    if (index == 4) {
        double res = 0;
        for (auto sign: signs) {
            res = applySign(applySign(nums[0], applySign(nums[1], nums[2], (sign >> 2) & 3), sign & 3), nums[3],
                               (sign >> 4) & 3);
            if (abs(res -24)<.01 )
                return true;
            res = applySign(applySign(applySign(nums[0], nums[1], sign & 3), nums[2], (sign >> 2) & 3), nums[3],
                               (sign >> 4) & 3);
            if (abs(res -24)<.01)
                return true;
            res = applySign(
                nums[0], applySign(applySign(nums[1], nums[2], (sign >> 2) & 3), nums[3], (sign >> 4) & 3), sign & 3);
            if (abs(res -24)<.01)
                return true;
            res = applySign(
                nums[0], applySign(nums[1], applySign(nums[2], nums[3], (sign >> 4) & 3), (sign >> 2) & 3), sign & 3);
            if (abs(res -24)<.01)
                return true;
            res = applySign(applySign(nums[0], nums[1], sign & 3), applySign(nums[2], nums[3], (sign >> 4) & 3),
                               (sign >> 2) & 3);
            if (abs(res -24)<.01)
                return true;
        }
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        nums[index] = cards[i];
        if (CheckNums(cards, visited, signs, nums, index + 1, result)) {
            result = true;
            return true;
        }
        visited[i] = false;
    }
    return false;
}

bool LeetCode67924Game::judgePoint24(vector<int> &cards) {
    // 0 +
    // 1 -
    //2 *
    //3 /
    vector<char> signs(64);
    iota(signs.begin(), signs.end(), 0);
    vector<double> nums(4, 0);
    // (a,(a,a)),a 0
    //((a,a),a),a 1
    // a,((a,a),a 2
    // a,(a,(a,a)) 3
    //(a,a),(a,a) 4
    bool result{false};
    vector<bool> visited(4, false);
    CheckNums(cards,visited,signs,nums,0,result);
    return result;
}

void LeetCode67924Game::Run() {
    vector<int> cards = {4, 1, 8, 7};
    cout << judgePoint24(cards) << endl;
}
