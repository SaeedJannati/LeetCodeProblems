//
// Created by saeed on 10/23/25.
//

#include "LeetCode3461CheckIfDigitsAreEqualInStringAfterOperationsI.h"

#include <iostream>
#include <ostream>
using namespace std;

bool LeetCode3461CheckIfDigitsAreEqualInStringAfterOperationsI::hasSameDigits(string s) {
    string newString{};
    while (s.length() >2) {
        newString = "";
        newString.reserve(s.length());
        for (int i = 0, e = s.length() - 1; i < e; i++) {
            newString += ((s[i] - '0' + s[i + 1] - '0') % 10) + '0';
        }
        s = newString;
    }
    return s[0] == s[1];
}

void LeetCode3461CheckIfDigitsAreEqualInStringAfterOperationsI::Run() {
    string s = "3902";
    cout<<hasSameDigits(s)<<endl;
}
