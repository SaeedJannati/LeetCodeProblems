//
// Created by saeed on 4/1/25.
//

#include "LeetCode2140SolvingQuestionsWithBrainpower.h"

#include <iostream>
using namespace std;

long long GetPoints(vector<vector<int> > &questions, vector<long long> &dp, int length, int index) {
    if (index >= length)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    long long answer = questions[index][0] + GetPoints(questions, dp, length, questions[index][1] + index + 1);
    answer = max(answer, GetPoints(questions, dp, length, index + 1));
    dp[index] = answer;
    return dp[index];
}

long long LeetCode2140SolvingQuestionsWithBrainpower::mostPoints(vector<vector<int> > &questions) {
    int length = static_cast<int>(questions.size());
    vector<long long> dp(length, -1);
    dp[length - 1] = questions[length - 1][0];
    return GetPoints(questions, dp, length, 0);
}

void LeetCode2140SolvingQuestionsWithBrainpower::Run() {
    vector<vector<int> > questions{{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << mostPoints(questions);
}
